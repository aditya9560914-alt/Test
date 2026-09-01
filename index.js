// Initial Data Set
let tableData = [];

// Fetch API Data
async function fetchTodos() {
  try {
    const response = await fetch('https://jsonplaceholder.typicode.com/todos');
    
    if (!response.ok) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }
    
    const todos = await response.json();
    tableData = todos;
    return todos;
  } catch (error) {
    console.error('Fetch error:', error);
  }
}

// State Management
let currentPage = 1;
const rowsPerPage = 10; // Increased to 10 for better view of 200 items
let sortColumn = 'id';
let sortAscending = true;
let searchQuery = '';

// DOM Elements
const tableBody = document.getElementById('tableBody');
const searchInput = document.getElementById('searchInput');
const pageInfo = document.getElementById('pageInfo');
const prevBtn = document.getElementById('prevBtn');
const nextBtn = document.getElementById('nextBtn');
const userModal = document.getElementById('userModal');
const openModalBtn = document.getElementById('openModalBtn');
const closeModalBtn = document.getElementById('closeModalBtn');
const addUserForm = document.getElementById('addUserForm');

// Initialize & Render Table
function renderTable() {
  // 1. Filter Data (Safely converting numbers/booleans to string)
  let filteredData = tableData.filter(item => {
    const query = searchQuery.toLowerCase();
    const statusText = item.completed ? 'completed' : 'pending';
    
    return item.title.toLowerCase().includes(query) ||
           String(item.id).includes(query) ||
           String(item.userId).includes(query) ||
           statusText.includes(query);
  });

  // 2. Sort Data
  filteredData.sort((a, b) => {
    let valA = a[sortColumn];
    let valB = b[sortColumn];

    if (typeof valA === 'string') {
      valA = valA.toLowerCase();
      valB = valB.toLowerCase();
    }

    if (valA < valB) return sortAscending ? -1 : 1;
    if (valA > valB) return sortAscending ? 1 : -1;
    return 0;
  });

  // 3. Paginate Data
  const totalPages = Math.ceil(filteredData.length / rowsPerPage) || 1;
  if (currentPage > totalPages) currentPage = totalPages;

  const startIndex = (currentPage - 1) * rowsPerPage;
  const paginatedData = filteredData.slice(startIndex, startIndex + rowsPerPage);

  // 4. Render Rows
  tableBody.innerHTML = '';
  if (paginatedData.length === 0) {
    tableBody.innerHTML = `<tr><td colspan="5" style="text-align:center;">No matching records found.</td></tr>`;
  } else {
    paginatedData.forEach(row => {
      const isCompleted = row.completed;
      const statusClass = isCompleted ? 'active' : 'pending';
      const statusLabel = isCompleted ? 'Completed' : 'Pending';

      const tr = document.createElement('tr');
      tr.innerHTML = `
        <td>${row.id}</td>
        <td>User ${row.userId}</td>
        <td>${row.title}</td>
        <td><span class="status-badge ${statusClass}">${statusLabel}</span></td>
        <td><button class="btn danger" onclick="deleteRow(${row.id})">Delete</button></td>
      `;
      tableBody.appendChild(tr);
    });
  }

  // Update Pagination Controls
  pageInfo.textContent = `Page ${currentPage} of ${totalPages}`;
  prevBtn.disabled = currentPage === 1;
  nextBtn.disabled = currentPage === totalPages;
}

// Event Listeners: Search
searchInput.addEventListener('input', (e) => {
  searchQuery = e.target.value;
  currentPage = 1; // Reset to first page on search
  renderTable();
});

// Event Listeners: Sorting
document.querySelectorAll('#dataTable th[data-column]').forEach(header => {
  header.addEventListener('click', () => {
    const column = header.getAttribute('data-column');
    if (sortColumn === column) {
      sortAscending = !sortAscending;
    } else {
      sortColumn = column;
      sortAscending = true;
    }
    renderTable();
  });
});

// Event Listeners: Pagination
prevBtn.addEventListener('click', () => {
  if (currentPage > 1) {
    currentPage--;
    renderTable();
  }
});

nextBtn.addEventListener('click', () => {
  currentPage++;
  renderTable();
});

// Row Operations: Delete
function deleteRow(id) {
  tableData = tableData.filter(item => item.id !== id);
  renderTable();
}

// Modal Controls & Form Submission
openModalBtn.addEventListener('click', () => userModal.classList.add('active'));
closeModalBtn.addEventListener('click', () => userModal.classList.remove('active'));

addUserForm.addEventListener('submit', (e) => {
  e.preventDefault();

  const titleInput = document.getElementById('userName').value; // Using existing form field
  const statusInput = document.getElementById('userStatus').value;

  const newRecord = {
    id: tableData.length ? Math.max(...tableData.map(d => d.id)) + 1 : 1,
    userId: 1, // Default user ID
    title: titleInput,
    completed: statusInput === 'Active' || statusInput === 'Completed'
  };

  tableData.unshift(newRecord); // Add to top of array
  addUserForm.reset();
  userModal.classList.remove('active');
  renderTable();
});

// Initial Load & Execution Flow
async function init() {
  tableBody.innerHTML = `<tr><td colspan="5" style="text-align:center;">Loading data...</td></tr>`;
  await fetchTodos();
  renderTable();
}

init();
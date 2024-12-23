// JavaScript to toggle FAQ answers on click
document.querySelectorAll('.faq-item').forEach(item => {
    item.addEventListener('click', () => {
      item.classList.toggle('open');  // Toggle the open class
    });
  });
  // script.js

// Get all FAQ items
const faqItems = document.querySelectorAll('.faq-item');

// Add click event listener to each FAQ item
faqItems.forEach(item => {
  item.addEventListener('click', function() {
    // Toggle the "open" class on the FAQ item
    item.classList.toggle('open');
    
    // Toggle the "+" and "-" symbol on the icon
    const icon = item.querySelector('.toggle-icon');
    if (item.classList.contains('open')) {
      icon.textContent = '-';  // Change icon to minus when open
    } else {
      icon.textContent = '+';  // Change icon back to plus when closed
    }
  });
});

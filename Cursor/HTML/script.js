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

// Smooth scrolling for navigation links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        const target = document.querySelector(this.getAttribute('href'));
        if (target) {
            target.scrollIntoView({
                behavior: 'smooth',
                block: 'start'
            });
        }
    });
});

// FAQ functionality
document.querySelectorAll('.faq-item').forEach(item => {
    const question = item.querySelector('h3');
    const answer = item.querySelector('p');
    const toggleIcon = document.createElement('span');
    toggleIcon.className = 'toggle-icon';
    toggleIcon.textContent = '+';
    question.appendChild(toggleIcon);

    question.addEventListener('click', () => {
        const isOpen = item.classList.contains('open');
        
        // Close all other FAQ items
        document.querySelectorAll('.faq-item').forEach(otherItem => {
            if (otherItem !== item) {
                otherItem.classList.remove('open');
                otherItem.querySelector('.toggle-icon').textContent = '+';
            }
        });

        // Toggle current item
        item.classList.toggle('open');
        toggleIcon.textContent = isOpen ? '+' : '×';
    });
});

// Add scroll animation for elements
const observerOptions = {
    threshold: 0.1
};

const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('fade-in');
        }
    });
}, observerOptions);

// Observe all sections
document.querySelectorAll('section').forEach(section => {
    observer.observe(section);
});

// Mobile menu toggle
const createMobileMenu = () => {
    const header = document.querySelector('header');
    const nav = document.querySelector('.nav');
    
    // Create mobile menu button
    const menuButton = document.createElement('button');
    menuButton.className = 'mobile-menu-button';
    menuButton.innerHTML = '☰';
    header.insertBefore(menuButton, nav);

    // Toggle mobile menu
    menuButton.addEventListener('click', () => {
        nav.classList.toggle('active');
    });

    // Close mobile menu when clicking outside
    document.addEventListener('click', (e) => {
        if (!header.contains(e.target) && nav.classList.contains('active')) {
            nav.classList.remove('active');
        }
    });
};

// Initialize mobile menu
createMobileMenu();

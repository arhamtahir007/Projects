import React from 'react';
import './Contact.css';

const Contact = () => {
  return (
    <div className="contact">
      <div className="contact-container">
        <h1>Contact Us</h1>
        <p>
          We’d love to hear from you! Whether you have a question about our products, feedback on your experience, 
          or a business inquiry, feel free to reach out to us.
        </p>

        <div className="contact-details">
          <h2>Get in Touch</h2>
          <p><strong>Email:</strong> contact@testrogen.com</p>
          <p><strong>Phone:</strong> +1 (123) 456-7890</p>
          <p><strong>Office Address:</strong> 123 Bold Street, Confidence City, Manland 45678</p>
        </div>

        <h2>Send Us a Message</h2>
        <form className="contact-form">
          <label htmlFor="name">Your Name:</label>
          <input type="text" id="name" name="name" placeholder="Enter your name" required />

          <label htmlFor="email">Your Email:</label>
          <input type="email" id="email" name="email" placeholder="Enter your email" required />

          <label htmlFor="message">Your Message:</label>
          <textarea id="message" name="message" rows="5" placeholder="Write your message here" required></textarea>

          <button type="submit">Submit</button>
        </form>
      </div>
    </div>
  );
};

export default Contact;

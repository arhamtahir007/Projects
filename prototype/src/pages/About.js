import React from 'react';
import './About.css';

const About = () => {
  return (
    <div className="about">
      <div className="about-container">
        <h1>About Testrogen</h1>
        <p>
          Testrogen is a bold and empowering brand dedicated to crafting premium undergarments for men. 
          With the motto <span className="highlight">"For Man by Man"</span>, our mission is to redefine comfort, 
          quality, and style in men's undergarments. We aim to create products that not only fit perfectly but 
          also inspire confidence in every man who wears them.
        </p>
        <h2>Our Vision</h2>
        <p>
          At Testrogen, we believe that men deserve undergarments that reflect their strength, confidence, and individuality. 
          Our designs are carefully curated to blend durability with elegance, ensuring you feel your best every day.
        </p>
        <h2>Our Team</h2>
        <ul>
          <li><strong>Muhammad Miqdad Ahmad:</strong> Co-Founder & Visionary</li>
          <li><strong>Ahmad Waleed Akhtar:</strong> Product Designer</li>
          <li><strong>Moiz Ahmad:</strong> Marketing Specialist</li>
          <li><strong>Muhammad Arham:</strong> Technical Lead</li>
        </ul>
        <h2>Why Choose Testrogen?</h2>
        <p>
          Our products are designed with a focus on: 
          <ul>
            <li>Premium materials for lasting comfort</li>
            <li>Modern, bold aesthetics</li>
            <li>Attention to the unique needs of men</li>
          </ul>
        </p>
        <h2>Join the Revolution</h2>
        <p>
          We are not just a brand; we are a movement. Join us in redefining what it means to be bold, confident, and unstoppable.
        </p>
      </div>
    </div>
  );
};

export default About;

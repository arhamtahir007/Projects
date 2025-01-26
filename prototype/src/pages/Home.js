import React from 'react';
import { useNavigate } from 'react-router-dom';
import './Home.css';

const Home = () => {
    const navigate = useNavigate(); // Hook to navigate to another route

  const handleShopNow = () => {
    navigate('/products'); // Navigate to the products page when the button is clicked
  };
  return (
    <div className="home">
      {/* Hero Section */}
      <section className="hero">
        <h1>Welcome to <span className="brand">Testrogen</span></h1>
        <p>Your One-Stop Shop for Premium Men's Undergarments</p>
        <button className="cta-button" onClick={handleShopNow}>Shop Now</button>
      </section>

      {/* Features Section */}
      <section className="features">
        <h2>Why Choose Testrogen?</h2>
        <div className="feature-cards">
          <div className="feature-card">
            <h3>Premium Quality</h3>
            <p>Only the finest materials for unmatched comfort and durability.</p>
          </div>
          <div className="feature-card">
            <h3>Bold Style</h3>
            <p>Designed for men who want to stand out and feel confident.</p>
          </div>
          <div className="feature-card">
            <h3>Perfect Fit</h3>
            <p>Tailored for men of all sizes, ensuring a perfect and secure fit.</p>
          </div>
        </div>
      </section>

      {/* Product Highlights */}
      <section className="product-highlights">
        <h2>Featured Products</h2>
        <div className="products">
          <div className="product-card">
            <h3>Premium Boxer</h3>
            <p>Price: $20</p>
            <button>View Details</button>
          </div>
          <div className="product-card">
            <h3>Classic Brief</h3>
            <p>Price: $15</p>
            <button>View Details</button>
          </div>
          <div className="product-card">
            <h3>Undershirt</h3>
            <p>Price: $25</p>
            <button>View Details</button>
          </div>
        </div>
      </section>
    </div>
  );
};

export default Home;

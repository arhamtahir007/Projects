import React, { useState } from 'react';
import './ProductList.css';

const ProductList = () => {
  const [selectedCategory, setSelectedCategory] = useState('All');
  const products = [
    { id: 1, name: 'Premium Boxer', price: 20, size: 'M', category: 'Boxers', image: 'https://via.placeholder.com/300x200' },
    { id: 2, name: 'Classic Brief', price: 15, size: 'L', category: 'Briefs', image: 'https://via.placeholder.com/300x200' },
    { id: 3, name: 'Undershirt', price: 25, size: 'XL', category: 'Undershirts', image: 'https://via.placeholder.com/300x200' },
    { id: 4, name: 'Luxury Boxer', price: 30, size: 'M', category: 'Boxers', image: 'https://via.placeholder.com/300x200' },
    { id: 5, name: 'Comfort Brief', price: 18, size: 'L', category: 'Briefs', image: 'https://via.placeholder.com/300x200' },
    { id: 6, name: 'Classic Undershirt', price: 22, size: 'XL', category: 'Undershirts', image: 'https://via.placeholder.com/300x200' },
  ];

  const categories = ['All', 'Boxers', 'Briefs', 'Undershirts'];

  const filteredProducts = selectedCategory === 'All' ? products : products.filter(product => product.category === selectedCategory);

  return (
    <div className="product-list">
      <h1>Our Products</h1>

      {/* Filter Section */}
      <div className="filters">
        <label htmlFor="category">Filter by Category: </label>
        <select 
          id="category" 
          value={selectedCategory} 
          onChange={(e) => setSelectedCategory(e.target.value)} 
        >
          {categories.map((category, index) => (
            <option key={index} value={category}>{category}</option>
          ))}
        </select>
      </div>

      {/* Product Grid */}
      <div className="products-grid">
        {filteredProducts.map((product) => (
          <div key={product.id} className="product-card">
            <img src={product.image} alt={product.name} />
            <div className="product-info">
              <h3>{product.name}</h3>
              <p>Price: ${product.price}</p>
              <p>Size: {product.size}</p>
              <button>View Details</button>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default ProductList;

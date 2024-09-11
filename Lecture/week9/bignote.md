# CS50x 2024 - Lecture 8 - HTML, CSS, JavaScript

## Introduction
- Overview of Web Development: HTML, CSS, and JavaScript form the foundation of modern websites
- Importance: Define structure, style, and interactivity of web pages
- Brief History: Evolution from static websites to dynamic, responsive applications
- Current trends: Mobile-first design, progressive web apps, serverless architecture
- Future outlook: AI-powered web development, augmented reality integration

## The Internet
- Global network of interconnected computers
- Components: Servers, Clients, Routers
- Data Flow: Packet creation, routing, reassembly
- History: Originated from ARPANET in the 1960s
- Key milestones: World Wide Web invention, widespread adoption in the 90s
- Internet governance: ICANN, W3C, IETF roles

## TCP/IP
- Core protocols defining internet communication
- TCP: Ensures reliable, ordered, error-checked transmission
- IP: Handles addressing and routing
- TCP/IP Layers: Application, Transport, Internet, Network Access
- IP Addressing: Unique identification for internet-connected devices
- IPv4 vs IPv6: Differences, transition challenges, dual-stack implementations
- TCP handshake: Three-way connection establishment
- TCP congestion control: Slow-start algorithm, window scaling

## Ports
- Virtual endpoints for network communication
- Enable multiple services on single server/IP
- Common ports: 80 (HTTP), 443 (HTTPS), 21 (FTP), 25 (SMTP)
- Port ranges: Well-known (0-1023), registered (1024-49151), private/dynamic (49152-65535)
- Security implications: Open ports as potential vulnerabilities
- Port forwarding: Configuring routers for remote access
- Port knocking: Security technique for hiding services

## DNS (Domain Name System)
- Translates domain names to IP addresses
- Hierarchical structure: Root -> TLD -> Domain name records
- Process: Client request -> Local DNS resolver -> Root servers -> TLD servers -> Authoritative name server
- Benefits: DNS caching speeds up browsing
- DNS record types: A, AAAA, MX, NS, CNAME, TXT, PTR
- DNS security: DNSSEC for preventing spoofing, DANE for TLS authentication
- DNS propagation: Time required for changes to spread globally

## DHCP (Dynamic Host Configuration Protocol)
- Automatically assigns IP addresses
- Process: Discover -> Offer -> Request -> Acknowledge
- Advantages: Simplifies network administration
- Lease duration: Temporary nature of assigned IPs
- DHCP options: Providing additional configuration info (subnet mask, gateway, DNS servers)
- DHCP relay agents: Forwarding DHCP requests across subnets
- IPv6 autoconfiguration: Stateless Address Autoconfiguration (SLAAC)

## HTTP (Hypertext Transfer Protocol)
- Protocol for transferring web data
- Request-response cycle: Client request -> Server processing -> Response
- Methods: GET, POST, PUT, DELETE, PATCH, HEAD, OPTIONS, CONNECT
- HTTPS: Encrypted version for secure data transfer
- HTTP versions: 1.0, 1.1, 2.0 differences (persistent connections, pipelining)
- RESTful APIs: Using HTTP methods for stateless communication
- HATEOAS: Hypermedia As The Engine Of Application State
- HTTP caching: Cache-Control headers, ETag validation

## Inspect
- Developer tools in browsers
- Elements Tab: View HTML structure, live editing, DOM tree visualization
- Styles Tab: Edit CSS rules, computed styles, box model visualization
- Console: Run JavaScript for testing/debugging, error logging, console methods
- Network Tab: Monitor HTTP requests/responses, timing analysis, HAR export
- Performance Tab: Analyze rendering performance, flame charts
- Memory Tab: Debug memory leaks, heap snapshots
- Application Tab: Inspect storage, indexedDB, web workers
- Security Tab: View TLS certificate info, mixed content warnings

## Status Codes
- Numeric codes indicating HTTP request results
- Common codes: 200 OK, 301 Moved Permanently, 400 Bad Request, 404 Not Found, 500 Internal Server Error
- Categories: Informational, Successful, Redirection, Client Error, Server Error
- Custom status codes: Application-specific error handling
- Error pages: Creating custom responses for common errors

## HTML (Hypertext Markup Language)
- Building blocks of web pages
- Basic Structure:
  - `<!DOCTYPE html>`: Declaration of document type
  - `<html>`: Root element of the document
  - `<head>`: Contains metadata about the document
  - `<title>`: Sets the title of the page (appears in browser tab)
  - `<meta>`: Provides metadata about the document
  - `<link>`: Links external stylesheets or other resources
  - `<script>`: Includes or references executable scripts
  - `<style>`: Defines internal styles for the document
- Content Section (`<body>`):
  - Headers: `<h1>`, `<h2>`, ..., `<h6>`
  - Paragraphs: `<p>`
  - Lists:
    - Ordered lists: `<ol><li>Item</li></ol>`
    - Unordered lists: `<ul><li>Item</li></ul>`
    - Definition lists: `<dl><dt>Term</dt><dd>Description</dd></dl>`
  - Links: `<a href="url">Link Text</a>`
  - Images: `<img src="image.jpg" alt="Description">`
  - Tables:
    - `<table>`, `<tr>`, `<td>`, `<th>`
    - `<thead>`, `<tbody>`, `<tfoot>` for table structure
  - Forms:
    - `<form action="submit-url" method="post/get">`
    - Input fields: `<input type="text/password/email/etc." name="fieldName">`
    - attributes: `required`, `disabled`, `readonly`, `hidden`, `multiple`, `value`, `autofocus`, `autocomplete`, `pattern`, `min`, `max`, `step`, `size`, `checked`, `selected`, `minlength`, `maxlength`, `placeholder`.
    - Textareas: `<textarea rows="num" cols="num"></textarea>`
    - Checkboxes: `<input type="checkbox" name="option">`
    - Radio buttons: `<input type="radio" name="group" value="value">`
    - Submit button: `<button type="submit">Submit</button>`
  - Semantic Elements (HTML5):
    - `<header>`: Header section
    - `<nav>`: Navigation menu
    - `<main>`: Main content of the document
    - `<section>`: Self-contained composition
    - `<article>`: Independent piece of content
    - `<aside>`: Sidebar or tangentially related content
    - `<footer>`: Footer section
    - `<figure>` and `<figcaption>`: For images, diagrams, etc.
  - Multimedia:
    - Audio: `<audio controls><source src="audio.mp3" type="audio/mp3"></audio>`
    - Video: `<video width="320" height="240" controls><source src="movie.mp4" type="video/mp4"></video>`
  - Inline Elements:
    - `<span>`: Generic inline container
    - `<strong>`: Strong importance
    - `<em>`: Emphasis
    - `<i>`: Italic text
    - `<b>`: Bold text
    - `<u>`: Underlined text
  - Block-Level Elements:
    - `<div>`: Generic block-level container
    - `<pre>`: Preformatted text
    - `<blockquote>`: Long quotation
    - `<code>`: Computer code
    - `<samp>`: Sample output
    - `<kbd>`: Keyboard input
  - Interactive Elements:
    - `<details>` and `<summary>`: Collapsible content
    - `<dialog>`: Dialog box
    - `<menu>` and `<menuitem>`: Menu list
  - Metadata Elements:
    - `<base>`: Base URL for all relative URLs
    - `<noscript>`: Alternative content for users who have disabled scripts
    - `<canvas>`: Graphics, games, or other visual representations
    - `<svg>`: Scalable Vector Graphics
  - Obsolete Elements: Avoid using deprecated tags like `<center>`, `<font>`, `<strike>`, etc.

## Regular Expressions
Regular expressions (regex) are powerful tools used for searching, validating, and extracting data from strings. They offer a flexible way to match patterns in text, making them invaluable for various programming tasks.
### Syntax Elements
Regular expressions consist of several key elements:
1. **Character Classes**: Define sets of characters to match
   - `[abc]`: Matches any single character 'a', 'b', or 'c'
   - `[a-zA-Z]`: Matches any letter (lowercase or uppercase)
   - `\d`: Matches any digit
   - `\w`: Matches any word character (alphanumeric plus underscore)
2. **Quantifiers**: Specify how many times a pattern should be matched
   - `*`: Zero or more occurrences
   - `+`: One or more occurrences
   - `{n}`: Exactly n occurrences
   - `{min,max}`: Between min and max occurrences
3. **Anchors**: Specify the position of matches in a string
   - `^`: Start of the string
   - `$`: End of the string
   - `\b`: Word boundary
   - `\B`: Not a word boundary
4. **Groups**: Allow capturing matched text and creating subexpressions
   - `(pattern)`: Creates a capturing group
5. **Lookarounds**: Allow matching based on what precedes or follows a pattern
   - `(?=pattern)`: Positive lookahead
   - `(?!pattern)`: Negative lookahead
   - `(?<=pattern)`: Positive lookbehind
   - `(?<!pattern)`: Negative lookbehind
### Common Use Cases
Regular expressions are versatile tools with numerous applications:
1. **Form Validation**: Checking email addresses, phone numbers, passwords
2. **Search Functions**: Finding patterns in text documents
3. **Data Extraction**: Parsing log files, extracting information from web pages
4. **Password Strength Checking**: Ensuring passwords meet complexity requirements
### Tools and Resources
Several tools make working with regular expressions easier:
1. **Regex101**: An online regex tester and debugger (https://regex101.com/)
2. **regexr.com**: Another popular online regex testing tool (https://regexr.com/)
3. **Language-specific regex libraries**: Most programming languages have built-in regex support
### Common Patterns
Here are some frequently used regex patterns:
**Email Validation**:
```/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,}$/```
- This pattern validates most common email formats:
  - Starts with one or more alphanumeric characters, dots, underscores, percent signs, plus signs, or hyphens
  - Followed by '@' symbol
  - Then comes the domain name (one or more alphanumeric characters, dots, or hyphens)
  - Ends with a dot and at least two alphabetic characters for the top-level domain
**Phone Number (US Format)**:
```/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,}$/``` 
- This pattern matches US-style phone numbers
  - Optional opening parenthesis
  - Three digits
  - Optional closing parenthesis or seperator (-, ., space)
  - Three more digits
  - seperator (-, ., space)
  - Final four digits
**Credit Card Number**:
```/^(?:4[0-9]{12}(?:[0-9]{3})?|[25][1-7][0-9]{14}|6(?:011|5[0-9]{2})[0-9]{12}|3[47][0-9]{13})$/```
- This pattern matches most common credit card numbers:
  - Visa: Starts with 4, followed by 12 or 15 digits
  - Mastercard: Starts with 51-55 or 2221-2720, followed by 14 digits
  - American Express: Starts with 34 or 37, followed by 13 digits
  - Discover: Starts with 6011, 65, or 64[4-9], followed by 12 digits
### Password strength checking
```/^(?=.[a-z])(?=.[A-Z])(?=.\d)(?=.[@!!%*#?&]{8,}$/```
- This pattern enforces strong password requirements:
  - At least one lowercase letter
  - At least one uppercase letter
  - At least one digit
  - At least one special character (@$!%*#?&)
  - Minimum length of 8 characters
### Performance Considerations
When working with large datasets, optimizing regex patterns is crucial:
1. **Avoid Catastrophic Backtracking**: Be cautious with nested quantifiers
2. **Use Possessive Quantifiers**: In languages that support them (e.g., `++`, `*+`)
3. **Compile Regex Patterns**: When reusing patterns frequently
4. **Limit Alternatives**: Avoid excessive use of `|` in complex patterns
By understanding these concepts and best practices, you can effectively utilize regular expressions in your programming tasks, improving efficiency and accuracy in string manipulation and pattern matching.
via: validator.w3.org - let you validate your HTML and CSS.

## CSS (Cascading Style Sheets)
CSS is a fundamental technology for controlling the layout and appearance of web pages. It works alongside HTML to create visually appealing and well-structured websites.
### Syntax Elements
CSS consists of three main components:
1. Selectors: Identify which HTML elements to style
2. Properties: Define specific aspects of an element's appearance
3. Values: Specify the value for each property
### Box Model
The box model represents the structure of an HTML element:
1. Content Area: Where the actual content goes
2. Padding: Space between content and border
3. Border: Visible outline around the element
4. Margin: Space between the element and other elements
### Positioning Schemes
CSS offers several positioning methods:
1. Static: Default positioning scheme
2. Relative: Positioned relative to normal position
3. Absolute: Removed from normal flow, positioned relative to nearest positioned ancestor
4. Fixed: Fixed position relative to viewport
5. Sticky: Combines relative and fixed positioning
### Responsive Design
Techniques for creating adaptable layouts:
1. Media Queries: Apply styles based on device characteristics
2. Flexbox: Flexible layout system
3. Grid Layout: Two-dimensional layout system
### CSS Preprocessors
Tools that extend CSS functionality:
1. SASS (Syntactically Awesome StyleSheets): Supports variables, nesting, mixins
2. LESS
3. Stylus: Dynamic, expressive, robust, feature-rich CSS preprocessor
4. PostCSS: Transform CSS with JavaScript plugins
5. Myth: Preprocessor that compiles to vanilla CSS
6. Rework: Modular CSS processor
7. Pleeease: Postprocessor that bundles Autoprefixer, css-mqpacker, and cssnano
8. CSSnext: Postprocessor that allows you to use tomorrow's CSS syntax today
9. GSS: Generalized Style Sheets, a CSS preprocessor
10. Compass: Open-source CSS Authoring Framework
### CSS Frameworks
Pre-built collections of CSS and HTML templates for rapid development:
1. Bootstrap
2. Tailwind CSS
3. Foundation
4. Bulma
5. Material-UI
6. Semantic UI
7. Pure CSS
8. Tachyons
9. Milligram
10. Spectre.css
### CSS-in-JS
Libraries that allow writing CSS within JavaScript:
1. Styled Components
2. Emotion
### Animations and Transitions
Techniques for creating smooth visual effects:
1. Keyframe Animations: Complex animations defined using @keyframes rule
2. Transition Property: Smoothly changes CSS property over time
### CSS Grid
Two-dimensional layout system for creating complex grid structures.
### HTML Entities
Special characters represented using entity codes:
1. &#169;: Copyright symbol
2. &trade;: Trademark symbol
3. &copy;: Copyright sign
4. &reg;: Registered trademark sign
5. &nbsp;: Non-breaking space
6. &lt;: Less than sign
7. &gt;: Greater than sign
8. &amp;: Ampersand
9. &#39;: Single quotation mark
10. &#34;: Double quotation mark

## Bootstrap
Bootstrap is a popular front-end framework for building responsive websites and web applications. It provides a set of pre-built CSS and HTML components that can be easily customized and integrated into projects.
### Key Features
- **Grid System**: 12-column responsive grid system for creating consistent layouts
- **Components**: Pre-designed UI elements including navbars, buttons, forms, modals, and more
- **Customization**: Extensive customization options through Sass variables and overriding default styles
- **JavaScript Components**: Built-in JavaScript components like tooltips, popovers, carousels, and dropdowns
- **Accessibility**: Robust accessibility features with keyboard navigation support
- **Utility Classes**: Quick styling options for common design patterns
- **Theming**: Ability to create custom color schemes and typography
- **Responsive Design**: Built-in responsiveness for mobile-first design
- **Icons**: Glyphicons included by default
- **Plugins**: Extensible plugin ecosystem for adding new features
- **Build Process**: Offers a build process for customizing and compiling CSS and JS
### Advanced Usage
- **Component Variants**: Customize component variants for different states (active, disabled, etc.)
- **Custom CSS**: Inject custom CSS for global styling
- **JS Plugins**: Utilize JavaScript plugins for enhanced interactivity
- **Layout Options**: Create custom layouts using flexbox utilities
- **Typography**: Fine-tune typography with extensive options

## JavaScript
JavaScript is a client-side scripting language that enables dynamic interactivity on web pages. It's essential for creating modern, interactive web applications.
### Core Concepts
- **Variables**: Store and manipulate data
- **Functions**: Reusable blocks of code
- **Control Structures**: Conditional statements and loops
- **Data Types**: Primitive types (number, string, boolean), object, array
- **Object-Oriented Programming**: Classes and prototypes
### DOM Manipulation
- **Creating and Removing Elements**: Dynamically add or remove HTML elements
- **Modifying Attributes**: Change element attributes and properties
- **Event Delegation**: Efficiently handle events on dynamically added elements
- **Manipulating Styles**: Modify CSS properties of elements
- **Working with Forms**: Handling form submissions and validations
### Event Handling
- **Event Listeners**: Attach functions to respond to user interactions
- **Event Propagation**: Understand how events bubble up the DOM tree
- **Debouncing and Throttling**: Optimize performance for frequent event handlers
### AJAX and Async Operations
- **XMLHttpRequest**: Traditional method for asynchronous requests
- **Fetch API**: Modern, promise-based approach for fetching resources
- **Async/Await**: Simplify asynchronous code with cleaner syntax
- **Promises**: Handle asynchronous operations with callbacks and chaining
### Modern JavaScript (ES6+)
- **Arrow Functions**: Concise function syntax
- **Destructuring**: Extract values from objects and arrays
- **Template Literals**: Multiline strings with embedded expressions
- **Modules**: Organize code into reusable modules
- **Classes**: Define object-oriented behavior
- **Map and Set**: New collection types for unique values
### Frameworks and Libraries
- **React**: Component-based library for building user interfaces
- **Vue.js**: Progressive framework for building user interfaces
- **Angular**: Full-fledged application framework
- **jQuery**: Lightweight DOM manipulation library
- **Lodash**: Utility library for functional programming
- **Next.js**: React-based server-side rendering framework
### TypeScript
- **Type Annotations**: Add type information to improve code quality
- **Interfaces**: Define contract-like types
- **Generics**: Create reusable components with type parameters
- **Union Types**: Combine multiple types into a single type
### Web APIs
- **Geolocation**: Access device location
- **Web Storage**: Persist data locally in browser
- **Canvas**: Draw graphics and animations
- **WebGL**: High-performance 3D rendering
- **Service Workers**: Enable offline functionality and push notifications
### Browser Compatibility
- **Polyfills**: Ensure compatibility across different browsers
- **Feature Detection**: Safely check for browser support before using advanced features
- **Progressive Enhancement**: Build for older browsers while enhancing for newer ones

## Autocomplete
- JavaScript implementation using AJAX
- User input handling: Dynamic dropdown updates
- Accessibility considerations: Keyboard navigation, ARIA attributes
- Performance optimization: Debouncing, caching results
- Advanced features: Fuzzy matching, multiple selection
- Integration with backend: Fetching data from servers
- Error handling: Graceful degradation when network fails

## Geolocation
- API for accessing user location data (with permission)
- Data retrieval: Latitude and longitude, accuracy, timestamp
- Applications: Maps integration, location-based services, weather apps
- Privacy concerns: Respecting user privacy when requesting geolocation data
- Accuracy factors: GPS, Wi-Fi triangulation, cell tower positioning
- Geofencing: Creating virtual boundaries for location-based triggers
- Background geolocation: Tracking location when app is not active
- Fallback strategies: Handling devices without geolocation capabilities```

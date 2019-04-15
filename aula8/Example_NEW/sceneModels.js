//////////////////////////////////////////////////////////////////////////////
//
//  For instantiating the scene models.
//
//  J. Madeira - November 2018
//
//////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
//
//  Constructors
//


function emptyModelFeatures() {

	// EMPTY MODEL

	this.vertices = [];

	this.normals = [];

	// Transformation parameters

	// Displacement vector

	this.tx = 0.0;

	this.ty = 0.0;

	this.tz = 0.0;

	// Rotation angles

	this.rotAngleXX = 0.0;

	this.rotAngleYY = 0.0;

	this.rotAngleZZ = 0.0;

	// Scaling factors

	this.sx = 1.0;

	this.sy = 1.0;

	this.sz = 1.0;

	// Animation controls

	this.rotXXOn = true;

	this.rotYYOn = true;

	this.rotZZOn = true;

	this.rotXXSpeed = 1.0;

	this.rotYYSpeed = 1.0;

	this.rotZZSpeed = 1.0;

	this.rotXXDir = 1;

	this.rotYYDir = 1;

	this.rotZZDir = 1;

	// Material features

	this.kAmbi = [ 0.2, 0.2, 0.2 ];

	this.kDiff = [ 0.7, 0.7, 0.7 ];

	this.kSpec = [ 0.7, 0.7, 0.7 ];

	this.nPhong = 100;
}

function singleTriangleModel( ) {

	var triangle = new emptyModelFeatures();

	// Default model has just ONE TRIANGLE

	triangle.vertices = [

		// FRONTAL TRIANGLE

		-0.5, -0.5,  0.5,

		 0.5, -0.5,  0.5,

		 0.5,  0.5,  0.5,
	];

	triangle.normals = [

		// FRONTAL TRIANGLE

		 0.0,  0.0,  1.0,

		 0.0,  0.0,  1.0,

		 0.0,  0.0,  1.0,
	];

	return triangle;
}


function simpleCubeModel( ) {

	var cube = new emptyModelFeatures();

	cube.vertices = [

		-1.000000, -1.000000,  1.000000,
		 1.000000,  1.000000,  1.000000,
		-1.000000,  1.000000,  1.000000,
		-1.000000, -1.000000,  1.000000,
		 1.000000, -1.000000,  1.000000,
		 1.000000,  1.000000,  1.000000,
         1.000000, -1.000000,  1.000000,
		 1.000000, -1.000000, -1.000000,
		 1.000000,  1.000000, -1.000000,
         1.000000, -1.000000,  1.000000,
         1.000000,  1.000000, -1.000000,
         1.000000,  1.000000,  1.000000,
        -1.000000, -1.000000, -1.000000,
        -1.000000,  1.000000, -1.000000,
         1.000000,  1.000000, -1.000000,
        -1.000000, -1.000000, -1.000000,
         1.000000,  1.000000, -1.000000,
         1.000000, -1.000000, -1.000000,
        -1.000000, -1.000000, -1.000000,
		-1.000000, -1.000000,  1.000000,
		-1.000000,  1.000000, -1.000000,
		-1.000000, -1.000000,  1.000000,
		-1.000000,  1.000000,  1.000000,
		-1.000000,  1.000000, -1.000000,
		-1.000000,  1.000000, -1.000000,
		-1.000000,  1.000000,  1.000000,
		 1.000000,  1.000000, -1.000000,
		-1.000000,  1.000000,  1.000000,
		 1.000000,  1.000000,  1.000000,
		 1.000000,  1.000000, -1.000000,
		-1.000000, -1.000000,  1.000000,
		-1.000000, -1.000000, -1.000000,
		 1.000000, -1.000000, -1.000000,
		-1.000000, -1.000000,  1.000000,
		 1.000000, -1.000000, -1.000000,
		 1.000000, -1.000000,  1.000000,
	];

	computeVertexNormals( cube.vertices, cube.normals );

	return cube;
}


function cubeModel( subdivisionDepth = 0 ) {

	var cube = new simpleCubeModel();

	midPointRefinement( cube.vertices, subdivisionDepth );

	computeVertexNormals( cube.vertices, cube.normals );

	return cube;
}


function simpleTetrahedronModel( ) {

	var tetra = new emptyModelFeatures();

	tetra.vertices = [

		-1.000000,  0.000000, -0.707000,
         0.000000,  1.000000,  0.707000,
         1.000000,  0.000000, -0.707000,
         1.000000,  0.000000, -0.707000,
         0.000000,  1.000000,  0.707000,
         0.000000, -1.000000,  0.707000,
        -1.000000,  0.000000, -0.707000,
         0.000000, -1.000000,  0.707000,
         0.000000,  1.000000,  0.707000,
        -1.000000,  0.000000, -0.707000,
         1.000000,  0.000000, -0.707000,
         0.000000, -1.000000,  0.707000,
	];

	computeVertexNormals( tetra.vertices, tetra.normals );

	return tetra;
}


function tetrahedronModel( subdivisionDepth = 0 ) {

	var tetra = new simpleTetrahedronModel();

	midPointRefinement( tetra.vertices, subdivisionDepth );

	computeVertexNormals( tetra.vertices, tetra.normals );

	return tetra;
}


function sphereModel( subdivisionDepth = 2 ) {

	var sphere = new simpleCubeModel();

	midPointRefinement( sphere.vertices, subdivisionDepth );

	moveToSphericalSurface( sphere.vertices )

	computeVertexNormals( sphere.vertices, sphere.normals );

	return sphere;
}


//----------------------------------------------------------------------------
//
//  Instantiating scene models
//

var sceneModels = [];
max = 10;
for (var i=0; i<max ; ){
	var random = parseInt(Math.random()*5);
	console.log(random);
	switch (random) {
		case 0:
				sceneModels.push( new singleTriangleModel( ) );
				sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
				sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
				sceneModels[i].sz = Math.random()*0.5;
				i++
			break;
		case 1:
			sceneModels.push( new simpleCubeModel( ) );
			sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
			sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
			sceneModels[i].sz = Math.random()*0.5;
			i++
			break;
		case 2:
			sceneModels.push( new cubeModel( 1 ) );
			console.log(sceneModels);
			console.log(i);
			sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
			sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
			sceneModels[i].sz = Math.random()*0.5;
			i++
			break;
		case 3:
			sceneModels.push( new simpleTetrahedronModel( ));
			sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
			sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
			sceneModels[i].sz = Math.random()*0.5;
			i++
			break;
		case 4:
			sceneModels.push( new tetrahedronModel( 1 ));
			console.log(sceneModels);
			console.log(i);
			sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
			sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
			sceneModels[i].sz = Math.random()*0.5;
			i++
			break;
		case 5:
			sceneModels.push( new sphereModel( 1 ));
			sceneModels[i].tx=Math.random() ; sceneModels[i].ty= Math.random(); sceneModels[i].tz=Math.random()-1;
			sceneModels[i].sx = Math.random()*0.5; sceneModels[i].sy= Math.random()*0.5;
			sceneModels[i].sz = Math.random()*0.5;
			i++
			break;
		default:
			console.log(7777);
			break;

	}



}


// Model 4 --- Middle

//sceneModels.push( new simpleCubeModel() );

//sceneModels[4].sx = 0.1; sceneModels[4].sy = 0.75; sceneModels[4].sz = 0.1;

// Model 5 --- Middle

//sceneModels.push( new sphereModel( 3 ) );

//sceneModels[5].sx = 0.25; sceneModels[5].sy = 0.25; sceneModels[5].sz = 0.25;

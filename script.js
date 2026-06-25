const scene = new THREE.Scene();

const camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth / window.innerHeight,
    0.1,
    1000
);

const renderer = new THREE.WebGLRenderer({
    antialias: true
});

renderer.setSize(800, 500);

document
    .getElementById("cube-container")
    .appendChild(renderer.domElement);

camera.position.z = 8;

const cubeGroup = new THREE.Group();

for(let x=-1;x<=1;x++){
    for(let y=-1;y<=1;y++){
        for(let z=-1;z<=1;z++){

            const geometry =
                new THREE.BoxGeometry(
                    0.9,
                    0.9,
                    0.9
                );

            const material =
                new THREE.MeshBasicMaterial({
                    color:0xffffff,
                    wireframe:true
                });

            const cubie =
                new THREE.Mesh(
                    geometry,
                    material
                );

            cubie.position.set(
                x,
                y,
                z
            );

            cubeGroup.add(cubie);
        }
    }
}

scene.add(cubeGroup);

let dragging = false;
let prevX = 0;
let prevY = 0;

renderer.domElement.addEventListener(
    "mousedown",
    (e)=>{
        dragging = true;
        prevX = e.clientX;
        prevY = e.clientY;
    }
);

window.addEventListener(
    "mouseup",
    ()=>{
        dragging = false;
    }
);

window.addEventListener(
    "mousemove",
    (e)=>{

        if(!dragging) return;

        let dx = e.clientX - prevX;
        let dy = e.clientY - prevY;

        cubeGroup.rotation.y += dx * 0.01;
        cubeGroup.rotation.x += dy * 0.01;

        prevX = e.clientX;
        prevY = e.clientY;
    }
);

document
.getElementById("left")
.onclick = ()=>{

    cubeGroup.rotation.y -= 0.3;
};

document
.getElementById("right")
.onclick = ()=>{

    cubeGroup.rotation.y += 0.3;
};

document
.getElementById("reset")
.onclick = ()=>{

    cubeGroup.rotation.x = 0;
    cubeGroup.rotation.y = 0;
};

document
.getElementById("solve")
.onclick = ()=>{

    alert(
        "Backend not connected yet!"
    );
};

function animate(){

    requestAnimationFrame(
        animate
    );

    renderer.render(
        scene,
        camera
    );
}

animate();
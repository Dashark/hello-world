function changeText() {
    // 修改文字内容
    document.getElementById("helloText").innerHTML = "make some change!";

    // 动态添加一个button
    var rootDiv = document.getElementById("helloDiv");
    var button = document.createElement("button");
    button.innerHTML = "动态添加的按钮";
    rootDiv.appendChild(button);
}
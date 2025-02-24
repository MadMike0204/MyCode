<template>
  <h3>H3标签</h3>
  <p>{{ msg }}</p>
  <p>{{ hello }}</p>
  <p>{{ number+1 }}</p>
  <p>{{ ok?"yes":"no" }}</p>
  <p>{{ message.split('').reverse().join('') }}</p>
  <p>{{ rawHtml }}</p>
  <p>{{ x = 5 }}</p>
  <p v-html = "rawHtml" ></p>
  <p>{{ 16+"Volve" }}</p>
</template>

<!-- <script>
alert("Test")
</script> 
-->

<script>
export default {
  data(){
    return{
      msg:"JOJO",
      hello:"hello world",
      number:10,
      ok:true,
      message:"大家好",
      rawHtml:"<a href='https://www.baidu.com'>百度哈</a>"
    }
  }
}
</script>

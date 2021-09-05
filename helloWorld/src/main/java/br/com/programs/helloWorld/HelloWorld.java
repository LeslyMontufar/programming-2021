package br.com.programs.helloWorld;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloWorld {
    @GetMapping
    @ResponseBody
    public String hello(){
        return "Hello World!";
    }
}

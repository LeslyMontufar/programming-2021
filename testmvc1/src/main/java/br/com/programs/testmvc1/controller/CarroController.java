package br.com.programs.testmvc1.controller;

import br.com.programs.testmvc1.model.dao.CarroDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

@Controller
@RequestMapping("carros")
public class CarroController {

    @Autowired
    private CarroDao dao;

    @RequestMapping(value = "/listar", method = RequestMethod.GET)
    public ModelAndView listarCarros(ModelMap model) {
        model.addAttribute("carros", dao.getCarros());
        return new ModelAndView("/carro/list", model);
    }

}
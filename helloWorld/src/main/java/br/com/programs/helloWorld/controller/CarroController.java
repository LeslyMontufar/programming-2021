package br.com.programs.helloWorld.controller;

import br.com.programs.helloWorld.model.dao.CarroDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

@Controller
@RequestMapping("carros") //endereco request mapping intuitivo oq faz
public class CarroController {

    @Autowired // deixa o objeto pronto para quando precisar dele
    private CarroDao dao;

    @RequestMapping(value = "/listar", method = RequestMethod.GET)
    public ModelAndView listarCarros(ModelMap model) { //devolve objeto do tipo ModelAndView
        model.addAttribute("carros", dao.getCarros()); //lista de carros obtida a partir do DAO
        return new ModelAndView("/carro/list", model);
    }

}

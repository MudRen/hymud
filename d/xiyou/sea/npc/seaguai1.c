// Created by kuku@sjsh 2003.5.17
 
inherit NPC; 
#include <ansi.h>
       
void create() 
{ 
        if(random(2)==0)  
                set_name( "������", ({"old guai","guai"})); 
        else  
                set_name( "С����", ({"small guai","guai"})); 
        set("age", 50+random(100)); 
        set("gender", random(2)?"����":"Ů��"); 
        set("attitude", "aggressive"); 
        set("per", random(20)+1); 
        set("str", 100); 
        set("cor", 40); 
        set("con", 40); 
        set("int", 40); 
        set("spi", 40); 
        set("cps", 40); 
        set("kar", 40); 
        set("max_gin", 1000);
        set("kee", 5000); 
        set("max_kee", 5000); 
        set("eff_kee", 5000); 
        set("sen", 5000); 
        set("max_sen", 5000); 
        set("eff_sen", 5000); 
      
        create_family("�Ϻ�����ɽ",2 , "����");
        set("title",HIM"�˾�"NOR);
        set("class", "bonze");
        set("no_steal",1); 
        set("taskguai",1); 
        

        
        setup();

}


//���ҩ                                               

inherit ITEM; 
#include <ansi.h>                                                                              

int do_eat(string);                                                                         
void init();                                                                                

void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","������һ�ɣ����ҩ��ָ�们�䣡\n");                                       
    set("no_give","��ô����ҩ�����������ˣ�\n");                                        
    set("no_drop","��ô�����ҩ�����˶��ϧѽ��\n");                                        
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           

void create()                                                                               
{                                                                                           
  set_name("���ҩ", ({"houhui yao", "yao"}));                                    
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "��");                                                                      
    set("long", "һ����ɫ�ֵֹ�ҩ��ζ��һ������ô����\n");                                  
    set("value", 3500);                                                                        
    set("drug_type", "��Ʒ");                                                               
  }                                                                                         
  set("is_monitored",1);                                                                    
  setup();                                                                                  
}                                                                                           

int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="yao" && arg!="houhui yao")   return 0;                                          

  me->set("eff_jing", (int)me->query("max_jing"));                                            
  me->set("jing", (int)me->query("max_jing"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_qi", (int)me->query("max_qi"));                                            
   me->delete("mieyao_mudage"); 
   me->delete("secmieyao_mudage");                                                            
   me->delete("bad_mudage");                                                                
  me->set("qi", (int)me->query("max_qi"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("neili", (int)me->query("max_neili"));                                            
   message_vision(HIM "$N�Ѻ��ҩ������һ�ţ�����������һ������������                     
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           

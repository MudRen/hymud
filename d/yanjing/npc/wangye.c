inherit NPC;
void create()
{
   set_name("���պ���",({"wangye","wanyan"}));
   set("gender","����");
   set("long","���������.\n");
   set("mingwang",-10000);
   set("combat_exp",160000);
set("title","����ү");
   
   set("age",45);
   set("qi",6800);
   set("max_qi",6800);
   set("food",2500);
   set("water",2500);
   set("neili",3000);
   set("max_neili",3000);
   set("force_factor",20);

   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("parry",160);
   set_skill("unarmed",160);
   set_skill("club",160);
   set_skill("sword",160);

   setup();
   add_money("gold",1);
carry_object(__DIR__"obj/jinpao")->wear();
}

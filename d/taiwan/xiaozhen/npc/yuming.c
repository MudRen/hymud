inherit NPC;
void create()
{
      set_name("����",({"yuming","fisher","man"}));
      if (random(2)==1) 
      set("gender","����");
      else set("gender","Ů��");
      set("age",15+random(50));
      set("str",10+random(20));
      set("combat_exp",1000+random(1000));
      set("chat_chance",2);
      set("chat_msg",({
            "����˵��Щ�������������ڸǷ�ʱ�ڳ�����.\n",
            "ʦү˵��Ȼ����������������żҵ�����,����Ҳ�����Ų���������?\n",
            "��������������㶼Ҫ�Ƚ�������!\n",
         }));
     set_skill("dodge",20);
     set_skill("parry",20);
     set_skill("unarmed",20);
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",10+random(20));
}
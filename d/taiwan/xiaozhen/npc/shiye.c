inherit NPC;
void create()
{
   set_name("��ʦү",({"liang shiye","liang","shiye","liangshiye"}));
   set("gender","����");
   set("age",54);
   set("mingwang",-1000);
   set("long","��ʦү�㷨��ͨ,���������Ǿ���������!\n");
   set("combat_exp",700000);
   set("max_force",700);
   set("force",700);
   set("force_factor",20);
   set("chat_chance",10);
   set("chat_msg",({
        "��ʦү��ʳָմ�˵��ˮ,���Լ�����Ʋ������Ĩ��һ��!\n",
        "��ʦү�����ʲ�,һֻ�ּ���֧ë��,����ž������������!\n",
        "��ʦү����С���,�����̵ú��˿ڲ�!\n",
        "��ʦү������Ŷ�ƤС��,һ�߷ɿ�ط����ʲ�!\n",
   }));
  set_skill("unarmed",120);
  set_skill("literate",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",120);
  setup();
  carry_object("/clone/misc/cloth")->wear();
  add_money("gold",1);
}
  
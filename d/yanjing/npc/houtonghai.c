inherit NPC;
void create()
{
	set_name("��ͨ��",({"hou tonghai","hou"}));
   set("gender","����");
   set("mingwang",-9000);
   set("combat_exp",113000);
   set("title","��ͷ��");
 
   set("age",44);
   set("qi",11680);
   set("max_qi",11680);
   set("food",250);
   set("water",250);
   set("neili",11680);
   set("max_neili",11680);
   set("force_factor",20);
   set("chat_chance",7);
   set("chat_msg",({
  "��ͨ��ָ�ŵض���:�������������צ��̫����,�ҿɲ���ȥ.\n",
  "��ͨ�����˻��Դ��ϵ�����,��ض�̽ͷ̽�Ե�,����������ͷ��.\n",
  }));

   set_skill("dodge",340);
   set_skill("force",367);
   set_skill("parry",367);
   set_skill("unarmed",376);
   set_skill("club",334);
   set_skill("blade",356);
 
   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
}
void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
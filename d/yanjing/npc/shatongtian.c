inherit NPC;
void create()
{
   set_name("ɳͨ��",({"sha tongtian"}));
   set("gender","����");
   set("mingwang",-19000);
   set("combat_exp",153000);
   set("title","��������");
   set("long","�͹���ͺͷ������û���ͷ����˫Ŀ������˿����ͻ��.\n");

   set("age",54);
   set("qi",12880);
   set("max_qi",12880);
   set("food",250);
   set("water",250);
   set("neili",12880);
   set("max_neili",12880);
   set("force_factor",80);

   set_skill("dodge",380);
   set_skill("force",357);
   set_skill("parry",330);
   set_skill("unarmed",357);
   set_skill("club",337);
   set_skill("blade",378);
 
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
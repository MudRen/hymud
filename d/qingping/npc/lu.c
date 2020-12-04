 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("½�崨" , ({ "wuchuan", "lu wuchuan", "lu" }) );
        set("long", "��üͷ�������ƺ���ʲô�ⲻ�������⡣\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 48);
        set("gender", "����" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        create_family("��ƽɽׯ", 1, "ׯ��");
        set("combat_exp", 3000);
        set_skill("dodge", 50+random(50));
        set_skill("sword", 50);
        set_skill("qingpingsword", 45);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps"); 
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{       
   object me; 
   ::init();
   if(!query("given")) {
   add_action("do_answer","answer");
   me = this_player();
   if( interactive(me) && !is_fighting() ) {
      remove_call_out("greeting");
      switch (random(2)) {
         case 0:
            call_out("greeting", 1, me);
         break;
         case 1:
            call_out("ask_him", 5,me );
         break;
      }
   }
 }
}
void greeting(object me)
{
   if( !me || environment(me) != environment() ) return;
   message_vision("$Nҡͷ��������������ͬ����ʮϡ������÷��إһ֦��������
Բ�����£��Ű�������֪��\n",this_object(),me);
   return;
} 
int ask_him(object me)
{
   object obj; 
   obj = this_object();
   if(environment(me) == environment())
   tell_object(me,name()+"�����������ﲻ֪������������֮ʣ����������֮ʣ����
������֮ʣ�������Ｘ�Σ�����answer��\n");
   obj->set_temp("marks/asking",1);
   return 1;
} 
int do_answer(string arg)
{
   object me, obj, kite; 
   obj = this_object();
   me =this_player();
   if(!query_temp("marks/asking")) return 0;
   if(!arg) {
      message_vision(name()+"��������"+me->name()+"Ҳ�ﲻ���ң�\n", me);
      obj->set_temp("marks/asking", 0); 
      return 1;
   }
   if( arg == "23" )
   {
      message_vision(name()+"��������һ����������ˣ��ã�\n", me);
      switch(random(2)) {
         case 0:
            tell_object(me, name()+"����������ݽ�����Ҳ���õĵ���\n");
            message_vision(name()+"�ݸ�"+me->name()+"һ�����ݡ�\n", me);
            kite = new(__DIR__"obj/kite");
            kite->move(me);
            set("given",1);
         break;
         case 1:
            tell_object(me,name()+"��������������ܣ�����ƽɽׯ�ĺ�԰͸�ŹŹ֡�\n");
         break;
      }
        obj->set_temp("marks/asking", 0); 
      return 1;
   }
   else {
      tell_object(me, name()+"�����Ҿ��ò���ԣ�\n");
      obj->set_temp("marks/asking", 0); 
      return 1;
   }
}
void reset()
{
delete("given"); 
}      

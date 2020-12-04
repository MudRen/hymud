// Jay 3/17/96
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "hua hui", "hua", "hui"}));
        set("gender", "����");
        set("nickname", "һָ����");
        set("age", 60);
        set("long", "
�����Ǹ����̣��������������ݿ��£���ü���������ϴ�����
����װ������ñ�������ò���������ͷ��������ȴ�ֲ������ˡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 700000);
        set("shen", -7000);
      set("str", 55);
	set("int", 50);
	set("con", 58);
        set("dex", 55);
	
	set("max_qi", 39000);
	set("max_jing", 39000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("unarmed",300);
	set_skill("hammer",280);
	set_skill("tiexue-hammer",280);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 280);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 280);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 280);
	set_skill("parry", 280);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 250);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 250);
	set_skill("tongbi-zhang", 250);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 100);  
        setup();
        carry_object(__DIR__"obj/chui")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
}
void init()
{
        int i;
        object *ob, me;
        me = this_object();
        ob = all_inventory(environment(me));
        message_vision(HIY"ֻ��һֻ��Ӱ���������������ǰ��\n"NOR,me); 
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue; 
                if( !me->is_killing(ob[i]) ) me->kill_ob(ob[i]);
                call_out("checking", 3,  me);
        }     
        remove_call_out("do_back");
        call_out("do_back", 900,  me);  
}

int checking(object me)
{
	object ob;
        if(objectp(ob = present("corpse", environment(me)))){
	   destruct(ob);       
           tell_room(environment(me), me->query("name")+"�ٺ�һЦ����ʬ��һ���߿���\n", ({me}));
           call_out("checking", 2, me);
           return 1;
           }
        if (me->is_fighting()){
 	   call_out("checking", 1, me);
           return 1;
	   }
        remove_call_out("do_back");
  	call_out("do_back", 15, me);
	return 1;
}

void do_back(object me)
{                       
  object room;
  room = load_object("/d/hj/tianjin");
  room->set("exits", ([
              "north" : "/d/hj/mg-room1",          
         ]));  
  tell_room(environment(me), me->query("name")+"�������䣬�������ˡ�\n", ({me}));	
  destruct(me); 
  return;
}
void unconcious()
{    
	int i;
        object who = this_object()->query_temp("last_damage_from");
      command("faint");        
        if(who->query("jinyong/book6")==2)
{
	i = 500+random(800);
	who->set("jinyong/book6",3);
	who->add("combat_exp",i+9880);
	who->add("potential",i*15);
	who->add("mpgx",10);
	who->add("expmax",2);
 message_vision(CYN"$N��$n˵�����Ҵ���Ԫ������ʰ���! \n"NOR, this_object(), who);
	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
        who->save();
 }

      do_back(this_object());       
}
void die()
{
      do_back(this_object());       	
}
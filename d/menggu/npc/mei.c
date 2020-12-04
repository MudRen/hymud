// mei.c
inherit NPC;
#include <ansi.h>;
void create()
{
        set_name( "÷����" ,({ "mei chaofeng", "mei" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIB"��ʬ"NOR);
        set("gender", "Ů��");
        set("age", 32);
        set("long",
            "÷�����ǻ�ҩʦΨһ��Ů���ӣ��������ܻ�ҩʦ�۰�����ϧ����ʦ�ֳ�����\n"
            "������㺣�����͵�ˡ������澭�¾�˽����\n"
            "����ɫ�����Ϊ�þӺ����Ե���ڣ�ģ��ȴ��Ϊ�����������һ��������Ⱦ�\n"
            "ͨ�޷���\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",26500);
        set("max_jing",26000);
        set("neili", 22500);
        set("max_neili", 22500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 5200000);

        set_skill("claw", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 220);
        set_skill("jiuyin-baiguzhao", 320);
        set_skill("bibo-shengong", 290);
        set_skill("anying-fuxiang", 290);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
           "��ʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "÷����":   "��������ô�����ǰ׳հ���",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
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


void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book5")>=1))
	{
//::die();	
	}
        else if(who) {
  	if(!who->query("jinyong/book5") && who->query("combat_exp",1) >= 800000 )
{
		message_vision("$N˵������ �� ����\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",1);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+9000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}
        }
	call_out("leavet",1);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N�����򱱷���ȥ��\n" NOR,this_object());
        destruct(this_object());
}
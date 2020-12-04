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
        set("max_qi",36500);
        set("max_jing",36000);
        set("neili", 32500);
        set("max_neili", 32500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1200000);

        set_skill("claw", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 220);
        set_skill("jiuyin-baiguzhao", 320);
        set_skill("bibo-shengong", 320);
        set_skill("anying-fuxiang", 320);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1250);
        create_family("�һ���", 2, "�������");
        set("inquiry", ([
           "��ʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "����":     "�ߣ��������С�Ӱ�������ʦ�磬�Ҿ�����Ź�����",
           "�":     "�������ҵ�ͽ�ܣ��������ô��",
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

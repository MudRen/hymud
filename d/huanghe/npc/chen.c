// chen.c
inherit NPC;
#include <ansi.h>;
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void create()
{
        set_name( "������" ,({ "chen xuanfeng", "chen" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIY"ͭʬ"NOR);
        set("gender", "����");
        set("age", 35);
        set("long",
            "�����ǻ�ҩʦ�Ķ����ӣ���Ũü���ۣ���������������׳����ֻ��\n"
            "��ɫ΢΢���ơ�\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",55500);
        set("max_jing",55000);
        set("neili", 35500);
        set("max_neili", 35500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1500000);

        set_skill("claw", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 240);
        set_skill("jiuyin-baiguzhao", 380);
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
           "ͭʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "÷����":   "�����ҵ�ʦ�ã�Ҳ���ҵ����ҡ�",
           "������":   "��������ô�����ǰ׳հ���",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}



void kill_ob(object me)
{
	object ob = this_object();
	if (environment(ob)->query("short") == "ʯ��" && !objectp(present("mei chaofeng", environment(ob)))) {
		command("say �����ҵľ����澭��û��ô���ף�");
		message_vision(HIY"���������㼱�����У���·������ȥ��"NOR, me);
	        ob->add_temp("apply/attack", 200);
	        ob->add_temp("apply/damage", 200);
	        	        //ob->kill_ob(me);
	        me->start_busy(5);
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
	        ob->add_temp("apply/attack", -200);
		ob->add_temp("apply/damage", -200);
		ob->set("qi",55500);
		ob->set("eff_qi",55500);
		ob->set("neili",55500);
		ob->set("eff_neili",55500);

		command("out");
		this_object()->set_temp("book531",1);
		this_object()->set_temp("target", me->query("id"));
                this_object()->move("/d/huanghe/shamo1");
	}
        ::kill_ob(me);
}

void die()
{
	object ob = this_object(), me, obj,who;
	int i;
	if (!ob->query_temp("target")) {
	        call_out("do_die", 1, ob);
		return;
	}
	if (environment(ob)->query("short") != "ɳĮ"){
	        call_out("do_die", 1, ob);
		return;
	}
	me = ob->query_temp("last_damage_from");
	if (!me) return;
	who=me;
	if (me->query("id") != ob->query_temp("target")) {
		ob->revive(1);
		command("say �ã���Ȼ����" + me->name(1) + "���㣬�ߣ�");
		message_vision(HIY"����������Ʋ��ã�ת�����ˣ�\n"NOR, me);
		destruct(ob);
		return;
	}
	ob->delete_temp("target");


if((int)who->query("jinyong/book5")==2)
{
		message_vision("$N˵������ �� ����\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",3);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}

	if (me->query("jiuyin/full") || present("jiuyin xiajuan", me) || (!me->query("jiuyin/xia") && me->query("jiuyin/xia-failed") > 2)) {
	        call_out("do_die", 1, ob);
		return;
	}
	
	if (me->query("jiuyin/xia") && !present("jiuyin xiajuan", me)) {
		obj = new ("/clone/book/jiuyin-xia");
		obj->move(me);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������澭�¾�����\n"NOR, users());
	        call_out("do_die", 1, ob);
		return;
	}
	message_vision(HIW"$N��������ʬ��ĸ������˵㶫����\n"NOR, me);
	if (me->query("kar") > 40 && random(20) == 0) {
		if(present("bishou", me)) {
			message_vision(HIW"˳�ֳ��ذ�׸���һС��Ƥ������ϸһ�������Ǿ����澭�¾�\n"NOR, me);
			obj = new ("/clone/book/jiuyin-xia");
			obj->move(me);
			message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������澭�¾�����\n"NOR, users());
			me->delete("jiuyin/xia-failed");
			me->set("jiuyin/xia", 1);
		} else {
			message_vision(HIW"��ϧ$Nû�д���ذ�ף�ֻ����ʱ���ա�\n"NOR, me);
			me->add("jiuyin/xia-failed", 1);
		}
	} else {
		message_vision(HIW"��ϧ$N��û���⡣\n"NOR, me);
		me->add("jiuyin/xia-failed", 1);
	}
	call_out("do_die", 1, ob);
	return;
}

void do_die(object ob)
{
        :: die();
}

//ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		   +"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIR "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 130);
	set("int", 129);
	set("con", 130);
	set("dex", 128);

	set("qi", 568500);
	set("max_qi", 568500);
	set("jing", 555900);
	set("max_jing", 555900);
	set("neili", 558000);
	set("max_neili", 558000);
	set("jiali", 150);

	set("combat_exp", 19500000);
	set("score", 200000);

	set_skill("force", 1000);
	set_skill("unarmed", 1150);
	set_skill("dodge", 1150);
	set_skill("parry", 1150);
	set_skill("strike",170);
	set_skill("hand",1170);
	set_skill("training",1300);
	set_skill("staff", 1250);
	set_skill("hamagong", 980);
	set_skill("chanchu-bufa", 980);
	set_skill("shexing-diaoshou", 980);
	set_skill("lingshe-zhangfa", 980);
	set_skill("hamashengong", 980);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 3500);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);        

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.hama" :),
                (: command("unwield zhang") :),
                (: command("wield zhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.chanshen" :),                
                (: perform_action, "hand.huixuan" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "dodge.chanfei" :),                
        }) );
	create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
	setup();
    carry_object("/p/item/ritemtz3/wstaff38")->wield();
    
    carry_object("/p/item/ritemtz3/ahands17")->wear();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
}




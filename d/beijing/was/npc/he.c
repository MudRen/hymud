#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��̫��", ({ "he taichong", "he", "taichong" }));
        set("long", "һ����ʮ������������ӣ�üͷ������ԭ��\n"
                    "����������ɵ����ţ��˳ơ�������������\n"
                    "��̫�壬����������Χ��������֮�󣬱���\n"
                    "�ü����ã���Ѻ�����\n");
        set("title", "�����ɵ���������");
        set("nickname", WHT "��������" NOR);
        set("gender", "����");
        set("age", 58);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 8500);
        set("max_jing", 8200);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 100);
        set("combat_exp", 1400000);


	set("jiali", 50);

	set("score", 40000);

	set_skill("taiji-shengong", 180);
	set_skill("art", 280);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 220);
	set_skill("dodge", 240);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 320);
	set_skill("kunlun-zhang", 220);
	set_skill("parry", 265);
	set_skill("sword", 275);
	set_skill("liangyi-jian", 225);
	set_skill("xunlei-jian", 225);
	set_skill("mantian-huayu", 225);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-quan", 220);
set_skill("qixian-jian", 280);
	set_skill("goplaying", 280);
	set_skill("luteplaying", 280);

        set_skill("finger", 180);
	set_skill("hand", 180);	
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),            			
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
(: perform_action, "strike.yixing" :),  
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

        create_family("������", 3, "����");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/zhujian")->wield(); 
}

void init()
{
        add_action("begin","bi");
}

int accept_fight(object who)
{
        command("say �ߣ����Һ�̫���������ڣ�Ҳ�ɲ��������");
        return 0;
}

int accept_hit(object who)
{
        command("say �ߣ����Һ�̫���������ڣ�Ҳ�ɲ��������");
        return 0;
}

int accept_kill(object who)
{
        command("heng");
        command("say �Һ�̫�屻�����ù����ס�����û���Ҫ������Ҫɱ�Ͷ��ְɡ�");
        return notify_fail("ɲ�Ǽ���ֻ���²����֡�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ��¥����Ӱ�ζ����������������\n");
}

int begin()
{
        object weapon;
        object me=this_player();
        object obj=this_object();

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
        {
                command("say ������ȫʧ������ֻ�ܺ���Ƚ���");
                return notify_fail("��������̫�岢������������\n");
        }

        command("heng");
        command("say ���аɣ�");
        message_vision(HIY "$N����δ�䣬����һ���������񽣶�׼$n" HIY
                           "����бб�̳����������صմ������ǽ�����\n" NOR,
                           obj, this_player());

        me->set_temp("bi",1);
        set("anti",me);
        obj->kill_ob(this_player());
        this_player()->kill_ob(obj);
        return 1;
}

void die()
{
        if (objectp(query("anti")))
        {
                message_vision(CYN "\n����������üͷ������������������\n" NOR,
                                   this_object());

                query("anti")->set_temp("win_he",1);
                query("anti")->delete_temp("bi");
        }
::die();
}


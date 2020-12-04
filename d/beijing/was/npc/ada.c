#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a da", "a", "da" }));
        set("long", "�˱��񽣷�������ؤ���Ĵ���֮�ף�����\n"
                    "֮��������������ֻ����������죬������\n"
                    "���߰����ֱ�һ�㣬����ϵ��������š�\n"
                    "ʮ����ǰ��˵����Ⱦ�ز���������ʱ���˶�\n"
                    "����ϧ��������������������\n");
        set("title", "ؤ���Ĵ���֮��");
        set("nickname", HIW "�˱���" NOR);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("per", 20);
        set("str", 45);
        set("int", 45);
        set("con", 45);
        set("dex", 45);
        
        set("max_qi", 36000);
        set("max_jing", 32000);
        set("neili", 36000);
        set("max_neili", 36000);
        set("jiali", 150);
        set("combat_exp", 3000000);

       set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");
map_skill("strike", "hunyuan-zhang");
map_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2500);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("begin","bi");
}

int accept_fight(object who)
{
        command("say û�����ķԸ��Ҳ�����֡�");
        return 0;
}

int accept_hit(object who)
{
        command("say û�����ķԸ��Ҳ�����֡�");
        return 0;
}

int accept_kill(object who)
{
        command("say û�����ķԸ��Ҳ�����֣�ɱ����Ҳһ����");
        return notify_fail("ɲ�Ǽ���ֻ�����²����֡�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ��¥����Ӱ��"
                           "�����������������\n");
}

int begin()
{
        object weapon, env, shelf, sword;
        object me = this_player();
        object obj = this_object();
        env = environment(this_object());
        shelf = present("shelf", env);
        sword = present("yitian sword", shelf);

        if (objectp(present("a er", environment())))
        return 0;

        if (! me->query_temp("win_aer"))
        {
                command("heng");
                command("say ������˭��Ϊ�θղŲ���ս���������û�����ˡ�");
                return notify_fail("���������󲢲�����������\n");
        }

        if (! objectp(weapon = me->query_temp("weapon")))
        {
                command("say ��ֻ����ȱ�������");
                return notify_fail("���������󲢲�����������\n");
        }

        if (sword)
        {
                command("nod");
                command("bow");

                message_vision(CYN "ͻȻ�����ȵ��������ţ��������콣��$n" CYN
                               "������\n" NOR, obj, this_player());

                message_vision(CYN "����΢΢���˵�ͷ����������������\n\n" NOR,
                               obj, this_player());

                message_vision(CYN "��������ǰ��������" NOR + RED "��ľ����"
                               NOR + CYN "��һ�ģ��Ǻų����µ�һ�����" NOR +
                               WHT "���콣" NOR + CYN "��ʱ���Ծ�𣬷��簢��"
                               "���С�\n\n" NOR, obj, this_player());

                message_vision(HIW "ֻ����ಡ���һ���ƿ����죬�ų����µ�һ��"
                               "�������콣�ѱ������������С�\n\n" NOR, this_object(),
                               this_player());

                sword->move(this_object());
                sword->wield();

                command("say �����ˡ�");

                message_vision(HIR "��������һ����Х���������콣��â��ʱ������"
                               "������ˢˢˢˢ��������������$n" HIR "����Ҫ����"
                               "����ȥ��\n��֮�죬����֮��������ȷ����������"
                               "\n\n" NOR, this_object(),this_player());
        }

        call_out("do_unwield",3);
        me->set_temp("bi",1);
        set("anti",me);
        obj->kill_ob(this_player());
        this_player()->kill_ob(obj);
        return 1;
}

void unconcious()
{
        int i;
        object ob,who,fang;
        object me = this_player();
who=me;

        who = this_object()->query_temp("last_damage_from");
  	//if (!who) return;

        if (objectp(query("anti")))
        {
                message_vision(HIR "\n$n" HIR "���������������е����������б�"
                               "�����������������е����콣����Ȧס������ٸв���"
                               "����Ҫ������\n����ֻ���ؿ�һ�������$n" HIR "��"
                               "�����Ѿ����ض��롣\n\n" NOR, this_object(),
                               query("anti"));

                message_vision(HIR "$n" HIR "���Ʋ����ˣ�����������������������"
                               "��ȫ����������������ϡ�\n\n" NOR, this_object(),
                               query("anti"));

                message_vision(CYN "\n����һ��������ʱ�Ұף�̾�˿�����˵������"
                               "�ܺã������콣�����ȥ�ɣ���\n" NOR,
                               this_object());

                message_vision(CYN "��������$n" CYN "��ȻһЦ���漴������������"
                               "������˵������¹�������������������ˡ���\n" NOR,
                               this_object(), query("anti"));

                message_vision(HIR "ֻ�������������������Ӱ���໥ʹ�˸����񣬶�"
                               "����˵������$n" HIR "ֱ�˹�������\n" NOR,
                               this_object(), query("anti"));

                query("anti")->delete_temp("bi");
                query("anti")->delete_temp("win_he");
                query("anti")->delete_temp("win_asan");
                query("anti")->delete_temp("win_aer");
who=query("anti");
  if((int)who->query("jinyong/book12")==6)
{
		i = 1550+random(2000);
		who->set("jinyong/book12",7);
		who->add("combat_exp",i+16000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+16000)+"�㾭��"+
		           chinese_number(i*25)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		who->save();
}

                ob = new(__DIR__"hebiweng");
                ob->move("/d/beijing/was/was_lou4");
                if (objectp(ob)) ob->kill_ob(query("anti"));

                ob = new(__DIR__"luzhangke");
                ob->move("/d/beijing/was/was_lou4");
                if (objectp(ob)) ob->kill_ob(query("anti"));

                ob = present("zhao min");
                if (objectp(ob)) destruct(ob);

        }
        ::die();
}

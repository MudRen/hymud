#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({ "yan qi", "yan" }) );
        set("long",
         "���ߵ����������������е���С�������������۾���СС���죬\nЦ������ʱ�����������ѣ�����Ц��ʱ�������������ͱ�����\n������ɫҲ�׵ķ��࣬���������е㲻���׽���\n");
        set("attitude", "heroism");
        create_family("����ɽׯ",7,"��ׯ��");
    set("gender","Ů��");
        set("age",24);
        set("str", 36);
        set("cor", 50);
        set("cps", 25);
        set("agi",40);
        set("int",40);
        set("per",40);
        set("class","legend");
        
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor", 50);
        set("chat_chance",1);
        set("chat_msg", ({
        "���߶��Žţ��޺޵õ������Ǹ�ǧ���Ĵ��ӣ���ʱ��ȴ��ʲôţƢ������......\n\n��������ò��������ߵĽ�ҩ����...��...������Ǻ�ѽ����\n",
                                })  );
        set("inquiry",  ([
            "����·" : "��ͷ�ִ���Ϲ�ֱ��ְ׳յ���ţ��������������ɡ�\n",
            "��̫ƽ" : "���ֵ����˳����ߵĳ����߶������û��ҩ����.....��...\n",
            "����" : "���ó�����绹�Ǻ�ϲ�������ӵģ����������ϴ�����ǲ��ǡ�\n",
                ])                      ); 
	
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
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
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
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
        ::init();
       add_action("do_look","look");
} 
int do_look(string arg)
{ 
        if (arg == "yan" || arg == "yan qi")
        {
                write("���ߵ����������������е���С�������������۾���\n");
                write("СС���죬Ц������ʱ�����������ѣ�����Ц��ʱ��\n");
                write("�����������ͱ�����������ɫҲ�׵ķ��࣬���������е㲻���׽���\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
                write("��"+HIG "���������������۷�״̬��"NOR+"\n");
                write("�����ϴ�����\n");
                write("  "+HIC "��"NOR+"����(Cloth)\n");
                write("  "+HIC "��"NOR+"����(Sword)\n");
                return 1;
        }
        return 0;
} 
int accept_object(object me, object ob)
{
        object lin;
        if(ob->query("name") == "���ƿ" && ob->query("liquid/name")=="��ҩ")
        {
                me->set_temp("marks/���ƿ",1);
                me->start_busy(3);
                if (lin=present("lin taiping",environment(this_object()))) {
                        message_vision("���߷�����̫ƽ������ҩ����������̫ƽ����.......\n\n",me);
                        message_vision(RED"$N���ۡ���һ���³�һ��ں�Ѫ������������ЩѪɫ����\n\n"NOR, lin); 
                        if(!me->query("m_success/�����̫ƽ")){
                    command("touch " + me->query("id"));
                                command("say ��λ" + RANK_D->query_respect(me)+ "���������л��ֻҪ��Ը�⣬��������������ѧ���ˣ�\n");
                                me->set("m_success/�����̫ƽ",1);
                                me->add("score",500);
                }
                        if(!me->query("imbue/lin")) {
                                lin->imbue_event(me);
                        }
            } else {
                        command("say ��л��λ" + RANK_D->query_respect(me)+ "�Ľ�ҩ����������������ѧ���ˣ�\n");
                }
                return 1;
        }
        else
                tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
                return 0;      
}

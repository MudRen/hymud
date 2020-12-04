 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�պ��", ({ "suhong" }) );
        set("gender", "Ů��" );
        set("age", 31);
        set("str", 40);
        set("title", "�ϰ���");
        set("long",
                "��λ�ϰ�����б���ڹ�̨�ߣ�Ц����������㡣\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                                __DIR__"obj/yxrs",
                                __DIR__"obj/cddt",
                        __DIR__"obj/frsp",
                __DIR__"obj/ssqy",
                __DIR__"obj/ylzp",
                __DIR__"obj/pwym",
                __DIR__"obj/cwgp",
                __DIR__"obj/ychz",
                __DIR__"obj/jxyz",
                __DIR__"obj/zypg",
                __DIR__"obj/rxcy",
                __DIR__"obj/qcsh",
                __DIR__"obj/hyjp",
                __DIR__"obj/szpc",
                __DIR__"obj/glyc",
                __DIR__"obj/xcfs",
                __DIR__"obj/cpcy",
                __DIR__"obj/gzyq",
                __DIR__"obj/qcxr",
                __DIR__"obj/jymj",
                __DIR__"obj/glxj",
                __DIR__"obj/cpdx",
                __DIR__"obj/pxhy",
                __DIR__"obj/kzmt",
                __DIR__"obj/hhdq", 
        }));
        set_skill("unarmed",50);
        set_skill("jingang-quan",50);
        set_skill("dodge",50);
        set_skill("wuxing-dun",50);
        map_skill("dodge","wuxing-dun");        
        map_skill("unarmed","jingang-quan");
        setup();
        carry_object(__DIR__"obj/pink_cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N�۽Ǻ�Ц��������������$nһ�ۡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����΢�ڣ�¶����֬�����ۣ���$n�������֡�\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N����$nһ�ۣ�����������ӣ��С����Ц������\n",this_object(),ob);
                        break;
        }
} 
int accept_object(object who, object ob)
{
        int damount;
        if(ob->query("id") == "painting")
   {
                message_vision("$N���$nһ�ۣ�������λ"+ RANK_D->query_respect(who) + "�����۹⡣������ҷǳ�ϲ������Ҫ���ˡ�Ǯ��ֱ�ӻ㵽����ʻ��ϡ�\n",this_object(),who);
                damount = (int)who->query("deposit");
                damount += ob->query("real_value");
                // to make life more realistic
                who->add("richness",ob->query("real_value"));
                who->set("deposit", damount);
                return 1;
        }
        return 1;
} 


 //Tie
inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
void create()
{
    set_name("��ʯ��", ({ "wang", "shijiangfang" }) );
    set("gender", "����" );
    set("age", 49);
    set("long", @LONG
��ʯ������Ѿ��Ĵ��ˣ���˵�������ʱ���и�����ˡ�
������Ƕ��˵Ļ�����ʯ���������Ѿ����˺����ˡ�
LONG
        );
    set("combat_exp", 700);
    set("attitude", "friendly");
    set_skill("dodge", 50);
    set_skill("parry", 50);
	set("vendor_goods", ({
        __DIR__"obj/stone1",
        __DIR__"obj/stone2",
        __DIR__"obj/stone3",
        __DIR__"obj/stone4",
	}));
    set("inquiry", ([
        "����" : (: tell_him :),
        "yubotao" : (: tell_him :),
        "����" : (: tell_him2 :),
        "kangqi" : (: tell_him2 :),
        ]));
    setup();
    carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
    object ob; 
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    switch( random(10) )
    {
    case 0:
        say( " ��ʯ��Ц�ŵ�����λ"
             + RANK_D->query_respect(ob)
             + "����ʯʨ��ô�� \n");
        break;
    case 1:
        say( " ��ʯ��Ц�ŵ�����λ"
             + RANK_D->query_respect(ob)
             + "��������Ĵ���ʯ��������ˡ� \n");
        break;
    }
}  
int tell_him2()
{
    object me;
    me=this_player();
    if (me->query("combat_exp")<1000000) {
        tell_object(me,"��ʯ����������ô������ʶ�ҵĴ�����أ������������˵������ð��İɣ�\n");
        return 1;
        }
    tell_object(me,"��ʯ�������㣬���Ȼ��ʶ�ҵĴ���ˣ�������ʲôҪ��æ�ģ�����˵��\n");
    me->set_temp("marks/��ʯ��",1);
    return 1;
}  
int tell_him()
{
    object me;
    me = this_player();
    if(me->query_temp("marks/��ʯ��")) 
        message_vision("$N��$n��������Ȼ�����ۻ����������Ҷ��˵����ѣ�"
                       "�������ҿ����ɣ�\n",this_object(),me);
    else
        message_vision("$N��$n�������Ѿ������ۻ������ܰ�������ôϸ�Ļ��ˣ�\n",
                       this_object(),me);
    return 1;
}  
int accept_object(object me, object obj)
{
    if(me->query_temp("marks/��ʯ��") && obj->query("id") == "round jade" &&
        obj->query("need_fix") && !obj->query("fixed"))
    {
        obj->set("fixed",1);
        obj->set("long","һ����������ĥ�ɵ��񻡣���Լ�а˴������֮һ԰��
������һ͹һ���������ۡ�\n");
        message_vision("$N��$n�ӹ�ȥ����$n�����˿̳�һ͹һ���������ۡ�\n",
                       this_object(),obj);
        notify_fail(name()+"���������ϵĳ����������񻡸������㡣\n");
    } 
    return 0;
}       

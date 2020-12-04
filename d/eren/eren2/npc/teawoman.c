 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�ϸ���", ({ "oldwoman" }) );
        set("gender", "Ů��" );
        set("age", 60);
        set("long",
                "�ϸ��˳��Ű��������������£���ǰ���Ÿ������ͼ������롣\n");
        set("combat_exp", 5);
        set("inquiry", ([
                "С��" : "С�̺���ͼ������������ֱ���",
                 "ŷ��������" : "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang ding" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang dang" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "������¥": "������¥��Ȼ�ǹ���������ඣ���˵���������ⲻ�ã�����Ϊԭ�Ϸ����ء�",
                "������ջ": "������ջ����������Ů�����ġ�",
                "��С��": "������ջ����������Ů����С�����ġ�",
                "���˹�": "�����Ƕ��ܹ��ˣ�����˹���������û�����ˡ�",
                "������": "�����������˭�˲��������ﻹ�����������ء�",
                "����": "����ҽ����������֮�ܡ�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
                "��Ƽ��": "������Ů����һ����ס���Ƕ����ֿ����ġ�",                   
        ])); 
        set("attitude", "friendly");
        
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
                __DIR__"obj/teapot",
               __DIR__"obj/dumpling",
               __DIR__"obj/fan",

	}));        
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "�ϸ���Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�ϸ�����ë��Ĩ��Ĩ����˵������λ" + RANK_D->query_respect(ob)
                                + "������������\n");
                        break;
                case 2:
                        say( "�ϸ���˵������λ" + RANK_D->query_respect(ob)
                                + "�����������Ųɵ��²�Ҷ����! ���㰡!...\n");
                        break;
        }
}       


// crazy_dog.c

inherit NPC;

void create()
{
	set_name("���ҹ���", ({ "playboy", "boy" }) );
	set("race", "����");
	set("age", 20);
	set("long", "��λ����һ���������Ĵ�磬���Ǵ������ʿ��Կ�������һ������ӵܡ�\n");
    set("shen_type",-1);
	set("attitude", "friendly");
	set("per", 5);	
	set("str", 26);
	set("cor", 30);
	set("rank_info/respect","����ү");
	set("gender","����");
	set_skill("unarmed",20);
	set_skill("dodge",30);
	set_skill("parry",20);
	set("combat_exp", 3000);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"���ҹ���˵����С������˫ȫ���Ÿ߰˶������ܺ������²������ˣ�"+"\n"+"����һ��ʢ������\n",
	}) );
	set("inquiry",([
		"��ʫ":
	"��˵���Ӳ�����ʫ�������Сү����һ�ף�....��.....\n"+
"��˵����޽��\n��ǰ��������ʣ�\n����Я�ù�����\n˭Ҫ��ǰ�Ǽ�������\n"
	]));
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"߾��Сү��δ�¹�˭��\n",
		"���ҹ���ͻȻ����������˫����ץ�Ҵ�ȴ��֪�����ڴ�˭��\n"
	}) );
	setup();
	add_money("silver",5);
}

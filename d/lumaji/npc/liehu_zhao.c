// liehu_zhao.c
// ÿ��ֻ����һ����.
// by Find.

#include <ansi.h>
#define MAX		10
#define GET_RATE	20

inherit NPC;

static mapping liewu = ([ "Ұɽ��":__DIR__"obj/shanji",
"���":__DIR__"obj/zhangzi",
"��¹":__DIR__"obj/milu",
"ɽ��":__DIR__"obj/shanhu", ]);

private string pay_request(object who,string name,int yufu);
string check_request(string id);

void create()
{
	set_name("����", ({ "old zhao", "zhao" }) );
	set("title","�Ի�");
	set("gender", "����" );
	set("age", 47);
	set("long", "��������һ�������������֣�����ÿ�δ��Ի�
���ջ��񣬶�����ʱ���ܴ�һЩ�����Ұ
�ޣ�������ô�򵽵�ȴ�����˵������һ
���Ի���Ҳ�Ǻ���ͷ�Եģ���������һЩ��
��Ұ������Ҳ���а취��������Ǯ�ɲ������
ѽ����������������ڡ����ԡ������顣 \n");

	set("chat_chance",10);
	set("chat_msg",({
	CYN"����˵��������ǰ�ҵ�������˵���Ի��ķ�����ڴ��Եĵط��ͷ����ϣ�������Ҳ���ܺͱ���˵����\n"NOR,
	CYN"����˵�������⸽����ɽ���в�������Ұ�ޣ����Ǻ��Ѵ򵽡���\n"NOR,
}));

	set("combat_exp", 20000);
	set("per", 30);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);

	setup();
	carry_object(__DIR__"obj/hupi")->wear();
if (random(2)==0)
carry_object(__DIR__"obj/shanji");
if (random(4)==0)
carry_object(__DIR__"obj/zhangzi");
if (random(8)==0)
carry_object(__DIR__"obj/milu");
if (random(16)==0)
carry_object(__DIR__"obj/shanhu");

}


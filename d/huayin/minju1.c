// Room: /d/huayin/minju1.c

inherit ROOM;

int is_hy_drying_room() { return 1; }

void create()
{
	set("short", "��ɷ�");
	set("long", @LONG
����һ�䲻��������������濿ǽ���Ų��ٴִ��ԭľ����
��������������¯�ӣ�͸��¯�ŵķ�϶���Կ���������Ļ��磬
һ������������̱���������˰�Χ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"minju",
]));

	setup();
}

void init()
{
	object ob = this_player();

	if(objectp(ob) && !wizardp(ob))
	{
		ob->delete_temp("valid_enter_drying_room");
		call_out("force_leave",90,ob);
	}
}

protected void force_leave(object who)
{
	if(!objectp(who) || (environment(who) != this_object()))
		return;

	tell_object(who,"���Գ���������µ�����˵����ô��ʱ�䲻���������ò�����������������\n����һ�Ѱ���ק�˳�ȥ��\n");
	who->move(__DIR__"minju");

	tell_room(__DIR__"minju",sprintf("���԰�%s�Ӻ�ɷ�ק�˳�����\n",who->name()));
}

inherit ROOM;
void create()
{
  set("short","�䵱ɽ��");
  set("long",@LONG
�䵱ɽ�ش��¶����紦��������Ҫ�����͵��֡�ԶԶ��ȥ��ɽ�ϱ鲼����
���֣� ���������ɽ��֮�������м������ᣬ�峺��Ϫˮ��ɽ���ж��˶��£�
���С�ӣ�����ȥ��
LONG);
  set("exits",([
    "southeast"   : __DIR__"xiaolu2",
  ]));
    set("objects",([
        "/clone/npc/man" : 1,
    ]));
    set("outdoors","zhongyuan");
  setup();
}


inherit ROOM;
void create()
{
  set("short","���ȹ�");
  set("long",@LONG
���ȹض�����ɽ���������أ��������纯���������ų����ա�ս��ʱ������
���ݹ��أ���ʮ�����ڹ���ҫ��������פ���˼�����Ҳû�ܹ��ƣ�ֻ�ø���ɢȥ
�������ͱ����ͳ���ս�������ۡ������һ�Ρ��عⷵ�ա���
LONG);
  set("exits",([
    "east"   : __DIR__"xiaoshan1",
    "northwest"   : __DIR__"tongguan",
  ]));
   set("outdoors","zhongyuan");
  setup();
}


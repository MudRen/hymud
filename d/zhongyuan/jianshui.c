inherit ROOM;
void create()
{
  set("short","��ˮ����");
  set("long",@LONG
�ӽ������ǣ�·�ϵ������������࣬�еĿ�����������ᣬ�е�ȴ��һ����
�Ӵ�硣��ʱ�����ž�װ�Ľ������ʹҴ��߹���Զ��һ�������ų��صĴ�����
��ȴ���ھֵ���ʦ����Ѻ�ڸ�·��
LONG);
  set("exits",([
    "east"   : __DIR__"nanmen",
    "west"   : __DIR__"mianchi",
  ]));
    set("outdoors","zhongyuan");
  setup();
}


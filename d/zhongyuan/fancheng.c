inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����λ�ں����������������Ǹ����������ں����뽭�����ؼ侭�̵Ļ�����
���ϴ�����Ϣ���������յ����ף�������������ҩ�ĵȻ���Ҵ�ʻ����������һ
Ƭ���ֵ�ũ�������������������������Ľ�����һ�����Ӵ�ɵĸ��ţ�����
�ž����������¡�
LONG);
  set("exits",([
    "north"   : __DIR__"baihe_an",
    "south"  : __DIR__"xiangyang",
  ]));
    set("outdoors","zhongyuan");
  setup();
}


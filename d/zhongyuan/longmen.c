inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����ʯ�ߣ���������������ɽ����ɽ�����Ӷ��ţ��������������Ż���ɽ��
�����о޴�ķ������ʢ���������Ĵ��ȵص�ɮ�¶���ǰ�����ݵġ�
    �ƴ���ʫ�˰׾��������ס����ɽ֮�ϣ��Ժš���ɽ��ʿ����������
���������
LONG);
  set("exits",([
    "north"   : __DIR__"nanmen",
    "southeast"  : __DIR__"tulu1",
  ]));
    set("outdoors","zhongyuan");
  setup();
}


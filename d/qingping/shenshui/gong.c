 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
һ���ߴ�ĵ��ã���ɽ��������˽�����ʵ������̾Ϊ��ֹ���ɼ���˼�˵�
�Ļ��Ƕ�ô����������Ƕ���ľ޴󡣵�ܴ��м�ȴû��һ�����ӣ�����
���������˸�ɫ�����ɺ�������м���һ�ŵ��Σ����ܾ�����վ�˼�����Ů��
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ 
  "southdown" : __DIR__"huoyan",
  "east" : __DIR__"shanfang",
  "west" : __DIR__"yaofang",
  "northeast" : __DIR__"woshi",
  "northwest" : __DIR__"qingong",
   ]));
   
   set("objects", ([
      __DIR__"npc/master" : 1,
      __DIR__"npc/girl": 3,
   ]) );
        set("coor/x",200);
        set("coor/y",12340);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}

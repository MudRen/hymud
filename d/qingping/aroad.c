 inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ����ʯС·�����������˻��ܣ�����Щҩ�ģ��Ե÷ǳ����ľ���
��ǰ�ǳ�������ʯ·��С·һ�˵ľ�ͷ�ƺ���һ��СԲ�ţ�·�����Ǽ��䷿
�ӣ�������ƽ���ӵ��������ڣ��˴���ӷ�ס�ϱ����䡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road2",
  "west" : __DIR__"ting",
   ])); 
        set("outdoors","qingping");
        set("coor/x",140);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   

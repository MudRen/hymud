 inherit ROOM;
void create()
{
        set("short", "�Ƕ�С��");
        set("long", @LONG
���Ƿ��ƳǶ���һ��С����Ҳ�Ǵ�����С��ȥ�����Ƴǵıؾ�֮·��·�ϵ�Ҳ�в���
���ˡ�·�ߵĻ��Ǻ�����ˮ������������ȥ����һ������ɫ��ɽ�壬��ɽ�ĵ�·��
�����档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"southeast" :AREA_PALACE"palace_path1",
  "northwest" : __DIR__"road5",
]));
        set("outdoors", "fengyun");  
        set("coor/x",80);
        set("coor/y",80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    

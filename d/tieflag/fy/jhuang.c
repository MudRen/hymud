inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���¾���ר�Ÿ����Ǯ���ܶ�İ�ȫ���������˶�Ҫ�������ǵ���ϸ�̲顣��
���������ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С��������
�Ƕ��ѱ������ڹ��ϣ�һ���־Ϳ����������ٶȰγ��Լ��ı��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jting",
  "east" : __DIR__"tang1",
  "west" : __DIR__"tang2",
  "north" : __DIR__"tang3",
]));
        set("objects", ([
        __DIR__"npc/huangyi" : 2,
        __DIR__"npc/huangyi2" : 1,
                        ]) ); 
    set("coor/x",-20);
        set("coor/y",-15);
        set("coor/z",0);
        setup();
        }      
int valid_leave(object me, string dir)
{
        object ob;
        if( !me->query_temp("jinqian") && me->query("class") != "assassin" && (dir == "north"|| dir== "west") && ob=present("guard leader", this_object())) {
        if(ob=present("guard leader", this_object())){
                return notify_fail("������ͳ��ŭ�⣺�����˵Ȳ�Ҫ�洦�߶���\n\n��������·��"+ob->name()+"��ס�ˡ�\n");
                } else if(ob=present("guard", this_object())){
                        return notify_fail(ob->name()+"��Ц���ǲ��������ȥ�ĵط���\n\n��������·��"+ob->name()+"��ס�ˡ�\n");
                }
        }
        return 1;
}  
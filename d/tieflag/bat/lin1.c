 //All Rights Reserved 1998 Apstone, Inc.
inherit ROOM; 
void create()
{
 set("short", "��ľ��");
 set("long",@LONG
������·������֦���߽���ľ���С����ӷǳ���������ʪ����������ˮ��̫��
��Ե�ʣ��������к���ζ�������������ô��һƬ��ľ�ָе��ǳ��Ծ��������ƺ�
����û��·�������˰��˸ߵ��Ӳݡ�
LONG);
         set("exits", ([
          "west" : "/d/tieflag/searoad1",
         ]));
         set("item_desc", ([
            "bush" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
            "��ľ��" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
            "��ľ" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
         ]));
         set("outdoors", "bat");
        set("coor/x",1100);
        set("coor/y",-290);
        set("coor/z",-10);
                setup();
}
void init()
{
    add_action("do_dash", "dash");
} 
int do_dash( string arg )
{
         object me,room;
         me = this_player();
         if(!arg || arg != "bush")
                return notify_fail("��Ҫ���Ķ�����\n");
         if(me->query_str()<30 || me->query("neili") < 500) {
                return notify_fail("���۵�����������Ҳû�д�����·����\n");
         }
         room = load_object(__DIR__"lin2");
         if(!objectp(room)) 
                return notify_fail("���۵�����������Ҳû�д�����·����\n");
    message_vision("$Nʹ������ľ����һ�������һ����ͷ���˽�ȥ��\n",me);
         me->move(room); 
         me->delete("force");
         return 1;
} 

 inherit ROOM;
void create()
{
        set("short", "����"); 
        set("long", @LONG
һ������ʮ�������ϸ��������ɵ����ݣ�����������������һ����ӿ����
��ɽ��������䡱����������ɽ���Х����������ҡҡ�λΣ�һ��������Ϳ��ܴ�
������׹����ٲ�������Ԩ��
LONG); 
        set("type","road");
        set("exits",([
        "down":__DIR__"cliffroad4",
        "southeast":__DIR__"moonrock",
        ]) );
       set("outdoors", "wolfmount");
        set("objects",([
            __DIR__"npc/zhongli":1,
        ]) );
        set("coor/x",-630);
        set("coor/y",-705);
        set("coor/z",80); 
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        object room;
        if( userp(me))
        {
        switch(random(6))
                {
                        case 0:
                                message_vision("�������ҵض����ţ�$N�����������ϻ�����ȥ����\n",me);
                                return notify_fail("���ã�û����ȥ��\n");
                                break;
                        case 1:
                                inv = all_inventory(me);
                                if(sizeof(inv)>=1)      
                                {
                                        ob = inv[random(sizeof(inv))];
                                        if (ob->query("no_drop") || ob->query("owner")) break;
                                        message_vision(ob->name()+"��$N���ϻ��˳���������������Ԩ��\n",me);
                                        destruct(ob);
                                }
                                return 1;
                                break;
                        case 2:
                                message_vision("$N�������ϲ�ס��ҡ���š�����\n",me);
                if ( me->query("kar") <= 20 )
                                {
                                        message_vision("������һ��ɱ���������Һ���$Nʧ��׹��������Ԩ����\n",me);
                                        me->unconcious();
                                        room = find_object(__DIR__"undercliff");
                                        if(!objectp(room)) room = load_object(__DIR__"undercliff");
                                        me->move(room);
                                        return 0;
                                }
                                else
                                       {
                                        message_vision("$N������ס�������������˿��������ڰ�ȫ�ˡ���\n",me);
                                        return 1;
                                }
                                break;
                        default:
                                return 1;
                                break;
                }
                return 1;
        }
        else
        return 1;
}     

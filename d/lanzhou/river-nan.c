// Room: /d/lanzhou/river-bei.c
// Date: netkill 98/08/17

inherit ROOM;
#define SHIP_TO __DIR__"river-bei"
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
    set("short", "�ƺ��ϰ�");
    set("long", @LONG
������һ����(river)�ߣ���ɫ�ĺ�ˮ��ӿ��������ȥ��������й���
ĸ�׺�---�ƺӡ��㿴��һ�����ܣ����ò�Զ����һ��С�ɿڣ��պ���һ��
�ɴ��������Ѿ��м����ˣ��ϴ���(chuanfu)�������㣬�������������
�������Ҫ�����ˡ�

LONG
    );

    set("exits", ([
        "south" : __DIR__"nroad4",
        "north" : __DIR__"bridge",
            ]));

    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ����(yell)һ�����Ҿ���������\n",
	"chuanfu" :"һ������ʵʵ�����꺺�ӣ������Ĵ�Ӧ�ò�����ʲô����ɡ�\n",
    ]));

    set("outdoors", "shaolin");
    setup();
}


/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹���������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "����һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ý��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ��ϴ���˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "�����̤�Ű��������������һ�㣬��������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "�����̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"river-bei");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
        object room, *ob;
        int i;

    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","�����̤�Ű����������ѱ���ʻ���ġ�\n", room);
        room->delete("yell_trigger"); 
                tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
                                else tell_room(room, "���������Ļ����ԹԵ����˴���\n", ob[i]);
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
                        }
                }

    }
}


int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("neili") < 300 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}
// This program is a part of NITAN MudLIB

/******************************************************
 * vrm_server.c                                       *
 * ���������Թ������� (Virtual Random Maze)         *
 *                                                    *
 * Written by Find.                                   *
 * Rewritten by Lonely@IsMUD.net                      *
 ******************************************************/

/******************************************************
 * ����Թ��Ĳ����㷨�����򵥣��Թ��Ĵ��澡����ʡ���� *
 * �壬�Թ������������������������Թ�����ֻ���� *
 * ����ߵ�ʱ�Ż�װ���ڴ棬�����Թ�����Ҳ����ͨ��ROOM *
 * һ����һ��ʱ��û�б��ο����������ٽ�ʡ�����壬���� *
 * ���Թ�һ��ʱ��û�б��ο������Ա���ȫ�ݻ٣��´����� *
 * Ҫ��ʱ������½������ֻ����һ���µ��Թ���������ʦ *
 * д������Թ�ֻ��涨һЩԤ��Ĳ������Թ��ĵ��߳��� *
 * �����������������������ʮ��������ǧ�����䡢·��ʱ *
 * ʱ��ͬ������Թ��ͽ������ˣ�������������д��Ч�� *
 * ����Ϸ�Ŀ����ԡ�                                   *
 * �����Ŀǰ�ʺ���������Թ��������Թ��ڷ���������� *
 * ����ͬ������һƬ���֡�һƬ�صصȣ���Ҫ����������� *
 * �������������һ������ڡ�һ����ֵ���������Ҫ *
 * �����Լ�������涨���Թ��ڷ���������һЩ����ʹ�� *
 * �ڷ���������仯�������������������Э����       *
 * ���ڲ���virtual object��ǣ�浽һ�㰲ȫ���⣬��Ҫ�� *
 * ���Լ���ϵͳ����������                             *
 * �������Թ������µ��㷨����Ҫ������ϸ��ʾ�Թ���·�� *
 * �ͱ����Լ��������������(by Lonely)��              *
 ******************************************************/

#pragma optimize

#define CENTER          4096    // �����ĵķ���
#define TRAP            2048    // ������ķ���
#define BOX             1024    // �б���ķ���
#define MAP             512     // �е�ͼ�ķ���
#define SPECIAL         256     // ����ķ���
#define T               128     // ���ڴ���ķ���
#define B               64      // �����ķ���
#define R               32      // ·���ϵķ���
#define D               16      // ��ʼ����ķ���
#define N               8       // �򱱳���
#define S               4       // ���ϳ���
#define W               2       // ��������
#define E               1       // �򶫳���
#define ALL             15      // ���г���
#define MAX_LONG        100     // ���߳�

#define RESET           CENTER | TRAP | BOX | MAP | SPECIAL
#define BOX_OB          "/clone/box/gboxnew"
#define TRAP_ROOM       "/inherit/trap"

#define TWO_VALID_LEAVES  // �涨�������ֻ������������
#define MAP_COMM    1     // �Թ���ͼ����ͨģʽ
#define MAP_DEEP    2     // �Թ���ͼ����ϸģʽ
#define MAP_NONE    3     // �Թ���ͼ�ǹر�ģʽ
#define BUSY        1     // �����BUSY
#define TRIP        2     // �����ˤ����ķ���
#define LOSTMAP     3     // ���Թ���ͼʧЧ
#define CHANGEMAP   4     // ���Թ���ͼˢ��
#define WOUND       5     // ���������
#define SPECIAL_MAP 1     // �Թ���ͼ��Ϊ��ϸģʽ
#define SPECIAL_DAN 2     // �ɵ�����Ʒ
#define JINKUAI     3     // ������Ʒ
#define GOLD        4     // �ƽ�
#define OBJ         5     // ������Ʒ
#define SPECIAL_OBJ 6     // Ӣ���̵���۵���Ʒ
#define NPC_SKILL   7     // ����NPC���书

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;

class coordinate{ int x; int y; }
class coordinate *newpath = ({}), *badpath = ({}), *roadpath = ({}),
        enter,/* ������� */
        leave;/* �������� */

static string *valid_dirs = ({ "south","north","west","east" });
static mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
]);
string base_dir(object obj) 
{ 
             string filename; 
             int at; 
     
             filename = base_name(obj); 
             at = strsrch(filename,"/",-1); 
            filename = filename[0..at];         
             return filename; 
} 
// ȫ�Թ���������.
static mixed *all;
// �Թ���ͼ����
static mixed line, line2;

/***************** �Թ���һЩԤ�����ԣ�*****************/
static int l;                           // �Թ��ĵ��߳�
static string *inherit_rooms = ({});      // �Թ�����̳еĵ�������
static string *valid_rooms = ({});        // �Թ���ʹ�õķ����ļ��� (****)
static string entry_dir;                // �Թ���ڷ���
static string link_entry_dir;           // �Թ��������������ӷ���
static string link_entry_room;          // �Թ�������������򵵰����ļ���
private int link_entry_room_x;          // �Թ���ڵ�x����
private int link_entry_room_y;          // �Թ���ڵ�y����
private int link_entry_room_z;          // �Թ���ڵ�z����
static string link_exit_dir;            // �Թ���������������ӷ���
static string link_exit_room;           // �Թ��������������򵵰����ļ���
static string entry_short;              // �Թ���ڵĶ�����
static string entry_desc;               // �Թ���ڵĳ�����
static string exit_short;               // �Թ����ڵĶ�����
static string exit_desc;                // �Թ����ڵĳ�����
static string center_room;              // �Թ�����λ�÷���
static string *maze_room_desc = ({});     // �Թ�����ĳ�����
static string maze_room_short;          // �Թ�����Ķ�����
static int is_outdoors = 0;             // �Թ������Ƿ�Ϊ����
static mixed maze_npcs;                 // �Թ��еĹ���
static mixed entry_npcs;                // �Թ���ڵĹ���
static mixed exit_npcs;                 // �Թ����ڵĹ���
static string *unique_rooms = ({});       // �Թ�Ψһ�ķ���
static string *special_rooms = ({});      // �Թ�����ķ���
private int refresh_delay = 0;          // �Թ��ؽ�ʱ��, default is 0 means no recreation
static int is_nodeath = 0;              // �Թ���������
static int random_rate = 0;             // �Թ�������ּ���
static int remove_time = 0;             // �Թ�����ʱ��
static int box_num = 0;                 // �Թ����������
static int trap_num = 0;                // �Թ����������
static int lonely_create = 0;           // �Թ�������ģʽ(Lonely)
/******************* ---- END ---- *********************/

static int handle_id;                   // �ų�
static int return_dir = 0;              // �Թ���ڷ���
static int map_status = MAP_COMM;       // �Թ��ĵ�ͼ״̬
static int display_coordinate = 1;      // �Ƿ���ʾ������ڵ�λ��
static object maze_boss;                // �Թ����BOSS

// �������.
static int maze_built = 0;

// �Թ�������Դת������
static int switch_flag = 0;

// ����ȫ�����.
protected void refresh_vars();

// �����Թ�
void create_maze();
void init_line();
varargs void init_maze(object room);
void init_road();
void init_room();
void init_special();

// ѡ���������.
protected varargs int random_out(int x,int y,int n);

// ��������.
protected void link_to_north(int x,int y);
protected void link_to_south(int x,int y);
protected void link_to_west(int x,int y);
protected void link_to_east(int x,int y);
protected void init_to_north(int x,int y);
protected void init_to_south(int x,int y);
protected void init_to_west(int x,int y);
protected void init_to_east(int x,int y);
protected mixed init_to_link(int x,int y);

nomask object query_maze_room(string str);
int query_maze_length(){ return l; }
protected string mroom_fname(int x,int y)
{ return sprintf("%s/%d/%d",base_name(this_object()),x,y);}

public mixed query_roadpath() { return roadpath; }
public mixed query_badpath() { return badpath; }
public mixed query_maze_boss() { return objectp(maze_boss) ? maze_boss : 0; }
public int query_map_status() { return map_status; }
public int query_remove_time() { return remove_time; }
public int is_maze() { return 1; }
int is_player_in(object room);
protected void refresh_vars() // ����ȫ�����.
{
        newpath = ({});
        badpath = ({});
        roadpath = ({});
        all = 0;
        line = 0;
        line2 = 0;
}

// ��һЩ��������ĺϷ��Լ��
protected int check_vars()
{
        int i,n;

        if( (l < 5) || l > MAX_LONG )
                return 0;

        if( !switch_flag ) {
                if( !stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
                        return 0;

                maze_room_desc -=({0});
                if( !n = sizeof(maze_room_desc) )
                        return 0;

                for( i=0;i<n;i++ )
                        if( !stringp(maze_room_desc[i]) || (maze_room_desc[i] == "") )
                                return 0;

                if( !stringp(maze_room_short) || (maze_room_short == "") )
                        return 0;
        } else {
                valid_rooms -=({0});
                if( !n = sizeof(valid_rooms) )
                        return 0;
                for( i=0;i<n;i++ )
                        if( !stringp(valid_rooms[i]) || (valid_rooms[i] == "") )
                                return 0;
        }
        /*
        if(!stringp(link_entry_dir) || (member_array(link_entry_dir,valid_dirs) == -1) )
                return 0;

        if(!stringp(link_exit_dir) || (member_array(link_exit_dir,valid_dirs) == -1) )
                return 0;
        */

        inherit_rooms -=({0});
        if( !n = sizeof(inherit_rooms) )
                return 0;

        for( i=0;i<n;i++ )
                if( !stringp(inherit_rooms[i]) || (inherit_rooms[i] == "") )
                        return 0;
        /*
        if( !stringp(link_entry_room) || (link_entry_room == "") )
                return 0;

        if( !stringp(link_exit_room) || (link_exit_room == "") )
                return 0;
        */
        if( !stringp(entry_short) || (entry_short == "") )
                return 0;

        if( !stringp(exit_short) || (exit_short == "") )
                return 0;

        if( !stringp(entry_desc) || (entry_desc == "") )
                return 0;

        if( !stringp(exit_desc) || (exit_desc == "") )
                return 0;

        return 1;
}

protected varargs int random_out(int x,int y,int n,int t) // ѡ��������ں���.
{
        int *outs = ({}), retn = 0;
        class coordinate temp;

        // The west room is (x-1,y)
        if( n&W
        && ((x-1) >= 0)
        && !(all[x-1][y]&D) )
        {
                if( !t ) {
                        if( lonely_create > 0 ) {
                                // �Թ���·�����췽�����з�����ڵķ���
                                if( !(return_dir&W)
                                && (y != leave->y || x > leave->x) )
                                        outs += ({ W });
                        } else
                                outs += ({ W });
                } else {
                        // һ��ļ��ʲ�·�������ͨ
                        if( random(2) == 1 )
                                outs += ({ W });
                }
        }

        // The east room is (x+1,y)
        if( n&E
        && ((x+1) < l)
        && !(all[x+1][y]&D) )
        {
                if( !t ) {
                        if( lonely_create > 0 ) {
                                if( !(return_dir&E)
                                && (y != leave->y || x < leave->x) )
                                        outs += ({ E });
                        } else
                                outs += ({ E });
                } else {
                        if( random(2) == 1 )
                                outs += ({ E });
                }
        }

        // The south room is (x,y-1)
        if( n&S
        && ((y-1) >= 0)
        && !(all[x][y-1]&D) )
        {
                if( !t ) {
                        if( lonely_create > 0 ) {
                                if( !(return_dir&S)
                                && (x != leave->x || y > leave->y) )
                                        outs += ({ S });
                        } else
                                outs += ({ S });
                } else {
                        if( random(2) == 1 )
                                outs += ({ S });
                }
        }

        // The north room is (x,y+1)
        if( n&N
        && ((y+1) < l)
        && !(all[x][y+1]&D) )
        {
                if( !t ) {
                        if( lonely_create > 0 ) {
                                if( !(return_dir&N)
                                && (x != leave->x || y < leave->y) )
                                        outs += ({ N });
                        } else
                                outs += ({ N });
                } else {
                        if( random(2) == 1 )
                                outs += ({ N });
                }
        }

#ifdef TWO_VALID_LEAVES
        // �������������,����ر�һ��.
        if( sizeof(outs) >= 3 )
                outs -= ({ outs[random(sizeof(outs))] });
#endif

        if( !t ) {
                // �������ִ������Թ�������
                if( lonely_create > 0 ) {
                        while( sizeof(outs) > 1 )
                                outs -= ({ outs[random(sizeof(outs))] });
                }
        }

        for( int i=0;i<sizeof(outs);i++ )
                retn |= outs[i];

        return retn;
}

void create_maze()
{
        int i;

        refresh_vars();         // ����ȫ�����.
        if( !check_vars() )     // ��һЩԤ��������м�顣
                return;

        all = allocate(l);
        for( i=0;i<l;i++ )
                all[i] = allocate(l);   //��������.

        enter = new(class coordinate);
        leave = new(class coordinate);

        switch( entry_dir ) {
                case "south":
                        // enter �������.
                        return_dir |= S;         // ·������ڵķ���
                        enter->x = to_int(l/2); // ȡ���Թ��Ƚ�ƽ��
                        enter->y = 0;
                        all[enter->x][enter->y] |= S; // | �� λ �����Ļ�
                        all[enter->x][enter->y] |= D;
                        if( lonely_create > 0 ) {     // ��ϸ��ͼģʽ����Ҫȷ�����ڷ���
                                leave->x = random(l);
                                leave->y = l-1;
                        }
                        break;
                case "north":
                        return_dir |= N;
                        enter->x = to_int(l/2);
                        enter->y = l-1;
                        all[enter->x][enter->y] |= N;
                        all[enter->x][enter->y] |= D;
                        if( lonely_create > 0 ) {
                                leave->x = random(l);
                                leave->y = 0;
                        }
                        break;
                case "west":
                        return_dir |= W;
                        enter->y = to_int(l/2);
                        enter->x = 0;
                        all[enter->x][enter->y] |= W;
                        all[enter->x][enter->y] |= D;
                        if( lonely_create > 0 ) {
                                leave->x = l-1;
                                leave->y = random(l);
                        }
                        break;
                case "east":
                        return_dir |= E;
                        enter->y = to_int(l/2);
                        enter->x = l-1;
                        all[enter->x][enter->y] |= E;
                        all[enter->x][enter->y] |= D;
                        if( lonely_create > 0 ) {
                                leave->x = 0;
                                leave->y = random(l);
                        }
                        break;
        }

        // ���Թ��ֲ����������
        init_special();

        // �����Թ�����
        init_maze();

        // �Թ���ʱˢ��
        if( refresh_delay > 0 )
                SCHEDULE_D->set_event(refresh_delay, 1, this_object(), "refresh_maze");
}

varargs void init_maze(object room)
{
        int i, x, y, exits;
        class coordinate temp, *valid_leaves = ({});
        string file, fname = base_name(this_object());
        object *temp_rooms = ({}), maze;

        if( objectp(room) ) {
                if( objectp(maze_boss) ) {
                        file = base_name(environment(maze_boss));
                        maze_boss->move(VOID_OB);
                }
                for( x=0;x<l;x++ ) {
                        for( y=0;y<l;y++ ) {
                                all[x][y] &= RESET; // ���²������ݳ�ʼ��
                                if( objectp(maze = find_object(sprintf("%s/%d/%d",fname,x,y))) ) {
                                        if( is_player_in(maze) ) {
                                                tell_room(maze, HIR "������������Ƶ������ӵ�������...\n"
                                                                HIR "ֻ�����ܹ�Ӱ�ζ������������ƺ��ڿ����ƶ�����һ�а������������⾰���ƺ������ı䡣\n" NOR);
                                                maze->delete("exits");
                                                temp_rooms += ({ maze });
                                        } else
                                                destruct(maze);
                                }
                        }
                }
                if( maze = find_object(sprintf("%s/entry",fname)) )
                        destruct(maze);
                if( maze = find_object(sprintf("%s/exit",fname)) )
                        destruct(maze);

                special_rooms = copy(unique_rooms);

                switch( entry_dir ) {
                case "south":
                        all[enter->x][enter->y] |= S; // | �� λ �����Ļ�
                        all[enter->x][enter->y] |= D;
                        break;
                case "north":
                        all[enter->x][enter->y] |= N;
                        all[enter->x][enter->y] |= D;
                        break;
                case "west":
                        all[enter->x][enter->y] |= W;
                        all[enter->x][enter->y] |= D;
                        break;
                case "east":
                        all[enter->x][enter->y] |= E;
                        all[enter->x][enter->y] |= D;
                        break;
                }
        }

        // ��ʼ����ͼ
        init_line();
        // ��ʼ��·��
        init_road();
        // �����·����ͨ������������
        init_room();

        if( !lonely_create ) {
                switch( entry_dir )
                {
                case "west":
                        for( i=0;i<l;i++ )
                                if( all[l-1][i] ) {
                                        temp = new(class coordinate);
                                        temp->x = l-1;
                                        temp->y = i;
                                        valid_leaves += ({temp});
                                }
                        break;
                case "east":
                        for( i=0;i<l;i++ )
                                if( all[0][i] ) {
                                        temp = new(class coordinate);
                                        temp->x = 0;
                                        temp->y = i;
                                        valid_leaves += ({temp});
                                }
                        break;
                case "south":
                        for( i=0;i<l;i++ )
                                if( all[i][l-1] ) {
                                        temp = new(class coordinate);
                                        temp->x = i;
                                        temp->y = l-1;
                                        valid_leaves += ({temp});
                                }
                        break;
                case "north":
                        for( i=0;i<l;i++ )
                                if( all[i][0] ) {
                                        temp = new(class coordinate);
                                        temp->x = i;
                                        temp->y = 0;
                                        valid_leaves += ({temp});
                                }
                        break;
                }

                if( !(i=sizeof(valid_leaves)) ) { // û�г��� �����½���
                        //log_file("static/maze",sprintf("%O\n",all));
                        call_other(this_object(),"create_maze");
                        return;
                }

                if( i == 1 )
                        leave = valid_leaves[0];
                else
                        leave = valid_leaves[random(i)]; // ���ѡһ��.
        }

        switch (entry_dir)
        {
                case "south":
                        all[leave->x][leave->y] |= N;
                        break;
                case "north":
                        all[leave->x][leave->y] |= S;
                        break;
                case "west":
                        all[leave->x][leave->y] |= E;
                        break;
                case "east":
                        all[leave->x][leave->y] |= W;
                        break;
        }

        line[leave->x*2+1][leave->y*2+1] =  HBRED "  " NOR;
        line2[leave->x*2+1][leave->y*2+1] = HBRED "  " NOR;

        // �Թ�������ϡ�
        maze_built = 1;
        
        if( objectp(room) || sizeof(temp_rooms) > 0 ) {
                if( objectp(maze_boss) )
                        maze_boss->move(load_object(file));
                
                for( i=0;i<sizeof(temp_rooms);i++ ) {
                        maze = temp_rooms[i];
                        if( sscanf(base_name(maze), fname+"/%d/%d", x, y) != 2 )
                                return;
                        
                        if( !exits = all[x][y] ) return;

                        if( exits&W ) maze->set("exits/west",mroom_fname(x-1,y));
                        else    maze->set("exits/west",mroom_fname(x,y));

                        if( exits&E ) maze->set("exits/east",mroom_fname(x+1,y));
                        else    maze->set("exits/east",mroom_fname(x,y));

                        if( exits&N ) maze->set("exits/north",mroom_fname(x,y+1));
                        else    maze->set("exits/north",mroom_fname(x,y));

                        if( exits&S ) maze->set("exits/south",mroom_fname(x,y-1));
                        else    maze->set("exits/south",mroom_fname(x,y));

                        if( x == enter->x && y == enter->y )
                                maze->set(sprintf("exits/%s",entry_dir),
                                        sprintf("%s/entry",fname));
                        if( x == leave->x && y == leave->y )
                                maze->set(sprintf("exits/%s",reverse_dir[entry_dir]),
                                        sprintf("%s/exit",fname));
                }
        }
}

void init_road()
{

        int x, y, out, numb;
        class coordinate temp, *valid_leaves = ({});

        // ������������.
        newpath += ({ enter });
        roadpath += ({ enter });

        // ������ѭ��.
        do {
                // ����һЩ������ʼ��.
                if( !(numb=sizeof(newpath)) )
                        continue;
                numb = random(numb);
                reset_eval_cost();
                x = newpath[numb]->x;
                y = newpath[numb]->y;

                // ������������ܵĳ�������ر�һ������:
                out = ALL^(all[x][y]); // ^ �� ��� ����
                out = random_out(x,y,out);

                if( !out ) { // û�п��ܵĳ�����.
                        newpath -= ({ newpath[numb] });
                        continue;
                }

                // ��������.
                if( out&W ) link_to_west(x,y);
                if( out&E ) link_to_east(x,y);
                if( out&N ) link_to_north(x,y);
                if( out&S ) link_to_south(x,y);

                // ��ǰ���䴦�����.
                newpath -= ({ newpath[numb] });
        }
        while( sizeof(newpath) );
}

void init_room()
{
        int i, j, x, y, out, numb, flag;
        class coordinate temp, *valid_leaves = ({});
        class coordinate tmp1, tmp2;
        mixed deadroom;
        mixed *alldead = ({});

        if( !lonely_create ) return;

        // ��·���ϵķ��������·
        do {
                // ����һЩ������ʼ��.
                if( !(numb=sizeof(roadpath)) )
                        continue;
                numb = random(numb);
                reset_eval_cost();
                x = roadpath[numb]->x;
                y = roadpath[numb]->y;

                out = ALL^(all[x][y]); // ^ �� ��� ����
                out = random_out(x,y,out,1);

                if( !out ) { // û�п��ܵĳ�����.
                        roadpath -= ({ roadpath[numb] });
                        continue;
                }

                // ��������.
                if( out&W ) init_to_west(x,y);
                if( out&E ) init_to_east(x,y);
                if( out&N ) init_to_north(x,y);
                if( out&S ) init_to_south(x,y);

                // ��ǰ���䴦�����.
                roadpath -= ({ roadpath[numb] });
        }
        while( sizeof(roadpath) );

        // ��ͨ����û�����ӵķ���
        for( i=0;i<l;i++ ) {
                for( j=0;j<l;j++ ) {
                        if( !(all[i][j]&D) ) {
                                // ����ķ�ʽ�н������ķ���ֱ�����ӵ���������(�����Թ����ӶȲ�����)
                                // �����ǽ������ķ����������,�п��ܻ�������ͬ,�����Ҫ���δ���
                                deadroom = init_to_link(i,j);
                                if( sizeof(deadroom) > 0 )
                                        alldead += ({ deadroom });
                        }
                }
        }

        while( sizeof(alldead) ) { // ����ѭ���������ķ���,ֱ�����ӵ������ķ���
                for( i=0;i<sizeof(alldead);i++ ) {
                        flag = 0;
                        for( j=0;j<sizeof(alldead[i]);j++ ) {
                                tmp1 = new(class coordinate);
                                tmp1 = alldead[i][j];
                                x = tmp1->x;
                                y = tmp1->y;
                                //x = alldead[i][j]->x;
                                //y = alldead[i][j]->y;
                                if( ((x-1) >= 0)
                                && !(all[x][y]&W)
                                && !(all[x-1][y]&B) ) {
                                        all[x][y] |= W;
                                        all[x-1][y] |= E;
                                        line[x*2][y*2+1] =  "  ";
                                        line2[x*2][y*2+1] = "  ";
                                        flag = 1;
                                        break;
                                }
                                if( ((x+1) < l)
                                && !(all[x][y]&E)
                                && !(all[x+1][y]&B) )  {
                                        all[x][y] |= E;
                                        all[x+1][y] |= W;
                                        line[x*2+2][y*2+1] =  "  ";
                                        line2[x*2+2][y*2+1] = "  ";
                                        flag = 1;
                                        break;
                                }
                                if( ((y+1) < l)
                                && !(all[x][y]&N)
                                && !(all[x][y+1]&B) )  {
                                        all[x][y] |= N;
                                        all[x][y+1] |= S;
                                        line[x*2+1][y*2+2] =  "  ";
                                        line2[x*2+1][y*2+2] = "  ";
                                        flag = 1;
                                        break;
                                }
                                if( ((y-1) >= 0)
                                && !(all[x][y]&S)
                                && !(all[x][y-1]&B) )  {
                                        all[x][y] |= S;
                                        all[x][y-1] |= N;
                                        line[x*2+1][y*2] =  "  ";
                                        line2[x*2+1][y*2] = "  ";
                                        flag = 1;
                                        break;
                                }
                        }

                        if( flag ) {
                                for( int k=0;k<sizeof(alldead[i]);k++ ) {
                                        tmp2 = new(class coordinate);
                                        tmp2 = alldead[i][k];
                                        x = tmp2->x;
                                        y = tmp2->y;
                                        //x = alldead[i][k]->x;
                                        //y = alldead[i][k]->y;
                                        all[x][y] ^= B;
                                        for( int n=0;n<sizeof(badpath);n++ ) {
                                                if( badpath[n]->x == x && badpath[n]->y == y )
                                                        badpath[n] = 0;
                                        }
                                        badpath -= ({ 0 });
                                }
                                alldead[i] = 0;
                        }
                }
                alldead -= ({ 0 });
        }

        if( sizeof(badpath) )
                log_file( "static/maze", sprintf("��%d�������ķ��䡣\n",
                          sizeof(badpath)) );
}

void remove_maze()
{
        object room;
        /*
        string fname = base_name(this_object());
        int x,y;

        if( handle_id )
                SCHEDULE_D->delete_event(handle_id);

        for( x=0;x<l;x++ )
                for( y=0;y<l;y++ )
                        if( objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))) )
                                destruct(room);
        if( room = find_object(sprintf("%s/entry",fname)) )
                destruct(room);
        if( room = find_object(sprintf("%s/exit",fname)) )
                destruct(room);
        */
        if( room = find_object(sprintf("%senter.c",base_dir(this_object()))) )
                destruct(room);
        if( room = find_object(sprintf("%sleave.c",base_dir(this_object()))) )
                destruct(room);

        destruct(this_object());
}

// �����Թ�����ʱ��
void set_remove_time(int t)
{
        remove_time = time() + t;
        handle_id = SCHEDULE_D->set_event(t, 0, this_object(), "remove_maze");
}

protected void link_to_west(int x, int y)        // The west room is (x-1,y)
{
        class coordinate temp;

        // �Ѿ��������Թ�����
        if( x == leave->x && y == leave->y ) {
                line[x*2+1][y*2+1] =  HBRED "  " NOR;
                line2[x*2+1][y*2+1] = HBRED "  " NOR;
                return;
        }

        temp = new(class coordinate);
        temp->x = x-1;
        temp->y = y;

        // ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
        if( all[temp->x][temp->y]&D )
                return;

        // �Թ����
        if( x == enter->x && y == enter->y ) {
                line[x*2+1][y*2+1] =  HBWHT "  " NOR;
                line2[x*2+1][y*2+1] = HBWHT "  " NOR;
        } else {
                // ����·������ɫ
                // ����Ѿ�����ɫ�ˣ���ʾ�б���������壬���ٸ��ĵ�ͼ
                if( line[x*2+1][y*2+1] == "  " ) {
                        line[x*2+1][y*2+1] = BGRN "  " NOR;
                }
        }

        all[x][y] |= W;
        all[x][y] |= R;
        all[temp->x][temp->y] |= E;
        all[temp->x][temp->y] |= D;
        newpath += ({ temp });
        roadpath += ({ temp }); // ·���ķ���

        line[x*2][y*2+1] = BGRN "  " NOR;
        line2[x*2][y*2+1] = "  ";
}

protected void link_to_east(int x,int y)        // The east room is (x+1,y)
{
        class coordinate temp;

        // �Ѿ��������Թ�����
        if( x == leave->x && y == leave->y ) {
                line[x*2+1][y*2+1] =  HBRED "  " NOR;
                line2[x*2+1][y*2+1] = HBRED "  " NOR;
                return;
        }

        temp = new(class coordinate);
        temp->x = x+1;
        temp->y = y;

        // ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
        if( all[temp->x][temp->y]&D )
                return;

        // �Թ����
        if( x == enter->x && y == enter->y ) {
                line[x*2+1][y*2+1] =  HBWHT "  " NOR;
                line2[x*2+1][y*2+1] = HBWHT "  " NOR;
        } else {
                // ����Ѿ�����ɫ�ˣ���ʾ�б���������壬���ٸ��ĵ�ͼ
                if( line[x*2+1][y*2+1] == "  " ) {
                        line[x*2+1][y*2+1] = BGRN "  " NOR;
                }
        }

        all[x][y] |= E;
        all[x][y] |= R;
        all[temp->x][temp->y] |= W;
        all[temp->x][temp->y] |= D;
        newpath += ({ temp });
        roadpath += ({ temp });

        line[x*2+2][y*2+1] = BGRN "  " NOR;
        line2[x*2+2][y*2+1] = "  ";
}

protected void link_to_south(int x,int y)       // The south room is (x,y-1)
{
        class coordinate temp;

        // �Ѿ��������Թ�����
        if( x == leave->x && y == leave->y ) {
                line[x*2+1][y*2+1] =  HBRED "  " NOR;
                line2[x*2+1][y*2+1] = HBRED "  " NOR;
                return;
        }

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y-1;

        // �϶˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
        if( all[temp->x][temp->y]&D )
                return;

        // �Թ����
        if( x == enter->x && y == enter->y ) {
                line[x*2+1][y*2+1] =  HBWHT "  " NOR;
                line2[x*2+1][y*2+1] = HBWHT "  " NOR;
        } else {
                // ����Ѿ�����ɫ�ˣ���ʾ�б���������壬���ٸ��ĵ�ͼ
                if( line[x*2+1][y*2+1] == "  " ) {
                        line[x*2+1][y*2+1] = BGRN "  " NOR;
                }
        }

        all[x][y] |= S;
        all[x][y] |= R;
        all[temp->x][temp->y] |= N;
        all[temp->x][temp->y] |= D;
        newpath += ({ temp });
        roadpath += ({ temp });

        line[x*2+1][y*2] = BGRN "  " NOR;
        line2[x*2+1][y*2] = "  ";
}

protected void link_to_north(int x,int y)       // The north room is (x,y+1)
{
        class coordinate temp;

        // �Ѿ��������Թ�����
        if( x == leave->x && y == leave->y ) {
                line[x*2+1][y*2+1] =  HBRED "  " NOR;
                line2[x*2+1][y*2+1] = HBRED "  " NOR;
                return;
        }

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y+1;

        // ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
        if( all[temp->x][temp->y]&D )
                return;

        // �Թ����
        if( x == enter->x && y == enter->y ) {
                line[x*2+1][y*2+1] =  HBWHT "  " NOR;
                line2[x*2+1][y*2+1] = HBWHT "  " NOR;
        } else {
                // ����Ѿ�����ɫ�ˣ���ʾ�б���������壬���ٸ��ĵ�ͼ
                if( line[x*2+1][y*2+1] == "  " ) {
                        line[x*2+1][y*2+1] = BGRN "  " NOR;
                }
        }

        all[x][y] |= N;
        all[x][y] |= R;
        all[temp->x][temp->y] |= S;
        all[temp->x][temp->y] |= D;
        newpath += ({ temp });
        roadpath += ({ temp });

        line[x*2+1][y*2+2] = BGRN "  " NOR;
        line2[x*2+1][y*2+2] = "  ";
}

protected void init_to_west(int x,int y)        // The west room is (x-1,y)
{
        class coordinate temp;

        temp = new(class coordinate);
        temp->x = x-1;
        temp->y = y;

        all[x][y] |= W;
        all[temp->x][temp->y] |= E;
        all[temp->x][temp->y] |= D;
        roadpath += ({ temp });

        // ����·����ͼ
        line[x*2][y*2+1] =  "  ";
        line2[x*2][y*2+1] = "  ";
}

protected void init_to_east(int x,int y)        // The east room is (x+1,y)
{
        class coordinate temp;

        temp = new(class coordinate);
        temp->x = x+1;
        temp->y = y;

        all[x][y] |= E;
        all[temp->x][temp->y] |= W;
        all[temp->x][temp->y] |= D;
        roadpath += ({ temp });

        line[x*2+2][y*2+1] =  "  ";
        line2[x*2+2][y*2+1] = "  ";
}

protected void init_to_south(int x,int y)       // The south room is (x,y-1)
{
        class coordinate temp;

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y-1;

        all[x][y] |= S;
        all[temp->x][temp->y] |= N;
        all[temp->x][temp->y] |= D;
        roadpath += ({ temp });

        line[x*2+1][y*2] =  "  ";
        line2[x*2+1][y*2] = "  ";
}

protected void init_to_north(int x,int y)       // The north room is (x,y+1)
{
        class coordinate temp;

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y+1;

        all[x][y] |= N;
        all[temp->x][temp->y] |= S;
        all[temp->x][temp->y] |= D;
        roadpath += ({ temp });

        line[x*2+1][y*2+2] =  "  ";
        line2[x*2+1][y*2+2] = "  ";
}

protected mixed init_to_link(int x,int y)
{
        int *outs = ({});
        int dir, retn = 0;
        class coordinate temp;
        mixed result = ({});

        all[x][y] |= T;

        if( ((x-1) >= 0)
        && !(all[x][y]&W) ) {
                if( !(all[x-1][y]&T)
                && !(all[x-1][y]&B) )
                        outs += ({ W });
        }

        if( ((x+1) < l)
        && !(all[x][y]&E) ) {
                if( !(all[x+1][y]&T)
                && !(all[x+1][y]&B) )
                        outs += ({ E });
        }

        if( ((y+1) < l)
        && !(all[x][y]&N) ) {
                if( !(all[x][y+1]&T)
                && !(all[x][y+1]&B) )
                        outs += ({ N });
        }

        if( ((y-1) >= 0)
        && !(all[x][y]&S) ) {
                if( !(all[x][y-1]&T)
                && !(all[x][y-1]&B) )
                        outs += ({ S });
        }

        if( sizeof(outs) < 1 ) {
                all[x][y] ^= T;
                if( !(all[x][y]&D) ) {
                        all[x][y] |= B;
                        all[x][y] |= D;
                        temp = new(class coordinate);
                        temp->x = x;
                        temp->y = y;
                        result = ({ temp });
                        badpath += ({ temp });
                }
                return result;
        }

        dir = outs[random(sizeof(outs))];
        retn |= dir;

        if( retn&N ) {
                temp = new(class coordinate);
                temp->x = x;
                temp->y = y+1;

                all[x][y] |= N;
                all[temp->x][temp->y] |= S;

                line[x*2+1][y*2+2] =  "  ";
                line2[x*2+1][y*2+2] = "  ";
        } else
        if( retn&S ) {
                temp = new(class coordinate);
                temp->x = x;
                temp->y = y-1;

                all[x][y] |= S;
                all[temp->x][temp->y] |= N;

                line[x*2+1][y*2] =  "  ";
                line2[x*2+1][y*2] = "  ";
        } else
        if( retn&W ) {
                temp = new(class coordinate);
                temp->x = x-1;
                temp->y = y;

                all[x][y] |= W;
                all[temp->x][temp->y] |= E;

                line[x*2][y*2+1] =  "  ";
                line2[x*2][y*2+1] = "  ";
        } else
        if( retn&E ) {
                temp = new(class coordinate);
                temp->x = x+1;
                temp->y = y;

                all[x][y] |= E;
                all[temp->x][temp->y] |= W;

                line[x*2+2][y*2+1] =  "  ";
                line2[x*2+2][y*2+1] = "  ";
        }

        if( !(all[temp->x][temp->y]&D) )
                result = init_to_link(temp->x, temp->y);

        all[x][y] ^= T;
        all[x][y] |= D;
        if( sizeof(result) > 0 ) {
                all[x][y] |= B;
                temp = new(class coordinate);
                temp->x = x;
                temp->y = y;
                badpath += ({ temp });
                result +=  ({ temp });
        }

        return result;
}

// ��ʼ����ͼ�Ĵ���
void init_line()
{
        class coordinate temp;
        int i, x, y, flag;

        line = allocate(l*2+1);  // ��ʾ��ϸ��ͼ
        line2 = allocate(l*2+1); // ��ʾ��ͨ��ͼ
        for( i=0;i<sizeof(line);i++ ) {
                line[i] = allocate(l*2+1);
                line2[i] = allocate(l*2+1);
        } // ��������

        for( y=sizeof(line)-1;y>=0;y-- ) {
                for( x=0;x<sizeof(line[y]);x++ ) {
                        if( y%2 == 1 ) {
                                if( x%2 == 1 ) {
                                        if( all[x/2][y/2]&MAP ) {         // �е�ͼ����
                                                line[x][y] = BYEL "  " NOR;
                                                line2[x][y] = "  ";
                                        } else if( all[x/2][y/2]&BOX ) {  // ����
                                                line[x][y] = BYEL "  " NOR;
                                                line2[x][y] = "  ";
                                        } else if( all[x/2][y/2]&TRAP ) { // ����
                                                line[x][y] = BMAG "  " NOR;
                                                line2[x][y] = "  ";
                                        } else if( all[x/2][y/2]&CENTER ) {  // ���ⷿ��
                                                line[x][y] = BCYN "  " NOR;
                                                line2[x][y] = "  ";
                                        } else if( all[x/2][y/2]&SPECIAL ) { // ���ⷿ��
                                                line[x][y] = BCYN "  " NOR;
                                                line2[x][y] = "  ";
                                        } else
                                                line[x][y] = line2[x][y] = "  ";
                                } else
                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                        } else {
                                if( x%2 == 1 )
                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                else {
                                        if( y == 0 ) {
                                                if( x == 0 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else if( x == l*2 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                        } else if ( y == l*2 ) {
                                                if( x == 0 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else if( x == l*2 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                        } else {
                                                if( x == 0 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else if( x == l*2 )
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                                else
                                                        line[x][y] = line2[x][y] = HIG "��" NOR;
                                        }
                                }
                        }
                }
        }
}

public string display_deep_map(object room)
{
        string map = "\n�Թ���ͼ��\n" WHT "��ɫ����" NOR "��ʾ�Թ���ڣ�"
                                      RED "��ɫ����" NOR "��ʾ�Թ����ڣ�"
                                      HIB "��ɫ�����" NOR "��ʾ�㵱ǰ��λ�á�\n"
                                      CYN "��ɫ����" NOR "��ʾ���ⷿ�䣻"
                                      YEL "��ɫ����" NOR "��ʾ�б��䣻"
                                      MAG "��ɫ����" NOR "��ʾ�����塣\n";
        int i, j;
        int x, y;

        if( !line )
                return "�Թ���ͼ�����ڡ�\n";

        if( objectp(room) ) {
                x = room->query("maze/x");
                y = room->query("maze/y");
        } else {
                x = -10;
                y = -10;
        }

        for( j=sizeof(line)-1;j>=0;j-- ) {
                for( i=0;i<sizeof(line[j]);i++ ) {
                        if( i == x*2+1 && j == y*2+1 )
                                map += replace_string(line[i][j], "  ", HIB "��" NOR);
                        else
                                map += line[i][j];
                }
                map += "\n";
        }
        return map;
}

public string display_common_map(object room)
{
        string map = "\n�Թ���ͼ��\n" WHT "��ɫ����" NOR "��ʾ�Թ���ڣ�"
                                      RED "��ɫ����" NOR "��ʾ�Թ����ڣ�"
                                      HIB "��ɫ�����" NOR "��ʾ�㵱ǰ��λ�á�\n";
        int i, j;
        int x, y;

        if( map_status == MAP_NONE )
                return 0;

        if( map_status == MAP_DEEP )
                return display_deep_map(room);

        if( !line2 )
                return "�Թ���ͼ�����ڡ�\n";

        if( objectp(room) ) {
                x = room->query("maze/x");
                y = room->query("maze/y");
        } else {
                x = -10;
                y = -10;
        }

        for( j=sizeof(line2)-1;j>=0;j-- ) {
                for( i=0;i<sizeof(line2[j]);i++ ) {
                        if( display_coordinate && i == x*2+1 && j == y*2+1 )
                                map += replace_string(line2[i][j], "  ", HIB "��" NOR);
                        else
                                map += line2[i][j];
                }
                map += "\n";
        }
        return map;
}

void init_special()
{
        int x, y, unique_num;
        class coordinate temp, *mazes = ({});

        unique_num = sizeof(unique_rooms);
        for( x=0;x<l;x++ ) {
                for( y=0;y<l;y++ ) {
                        if( x == l/2 && y == l/2 ) {
                                if( stringp(center_room) ) {
                                        all[x][y] |= CENTER;
                                        continue;
                                }
                                if( sizeof(unique_rooms) == 4 )
                                        continue;
                        }
                        if( unique_num > 0 && ((x == 0 && y == 0)
                        ||      (x == 0 && y == l-1)
                        ||      (x == l/2 && y == l/2)
                        ||      (x == l-1 && y == 0)
                        ||      (x == l-1 && y == l-1)) ) {
                                all[x][y] |= SPECIAL;
                                unique_num --;
                                continue;
                        }
                        if( (x == enter->x && y == enter->y) ||
                            (x == leave->x && y == leave->y) )
                                continue;

                        temp = new(class coordinate);
                        temp->x = x;
                        temp->y = y;
                        mazes += ({ temp });
                }
        }

        // �ֲ�����ͼ����
        temp = new(class coordinate);
        temp = mazes[random(sizeof(mazes))];
        x = temp->x;
        y = temp->y;
        all[x][y] |= MAP;
        mazes -= ({ temp });

        // �ֲ������ı���
        while( box_num > 0 ) {
                if( sizeof(mazes) < 1 )
                        break;
                temp = new(class coordinate);
                temp = mazes[random(sizeof(mazes))];
                x = temp->x;
                y = temp->y;
                all[x][y] |= BOX;
                mazes -= ({ temp });
                box_num --;
        }

        // �ֲ�����
        while( trap_num > 0 ) {
                if( sizeof(mazes) < 1 )
                        break;
                temp = new(class coordinate);
                temp = mazes[random(sizeof(mazes))];
                x = temp->x;
                y = temp->y;
                all[x][y] |= TRAP;
                mazes -=  ({ temp });
                trap_num --;
        }
        return;
}

// ˤ�ӵ��������
public object trip_maze(object room)
{
        int x, y;
        object next;
        string fname;

        if( !objectp(room) ) return 0;
        
        fname = base_name(this_object());
        
        while( 1 ) {
                x = random(l);
                y = random(l);
                if( (x == enter->x && y == enter->y) ||
                    (x == leave->x && y == leave->y) )
                        continue;

                if( x == room->query("maze/x") &&
                    y == room->query("maze/y") )
                        continue;         // �����Ǹ÷��䱾��

                if( all[x][y]&TRAP )
                        continue;

                next = load_object(sprintf("%s/%d/%d",fname,x,y));
                if( objectp(next) ) break;
        }
        return next;
}

// ���ָ�����������
public void remove_trap(object room)
{
        int x, y;

        if( !line ) return;

        x = room->query("maze/x");
        y = room->query("maze/y");
        if( all[x][y]&R )
                line[x*2+1][y*2+1] = BGRN "  " NOR;
        else
                line[x*2+1][y*2+1] = "  ";

        return;
}

nomask int clean_up()
{
        string fname;
        int x,y;
        object room;

        if( !maze_built ) {
                destruct(this_object());
                return 0;
        }

        // ��ʱȡ��
        return 1;

        fname = base_name(this_object());

        if( objectp(room = find_object(sprintf("%s/entry",fname))) ) {
                room->clean_up();
                if( objectp(room) )
                        return 1;
        }

        if( objectp(room = find_object(sprintf("%s/exit",fname))) ) {
                room->clean_up();
                if( objectp(room) )
                        return 1;
        }

        for( x=0;x<l;x++ )
                for( y=0;y<l;y++ )
                        if( objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))) ) {
                                //maze_objs += ({find_object(sprintf("%s/%d/%d",fname,x,y))});
                                room->clean_up();
                                if( objectp(room) )
                                        return 1;
                        }
        /*
        maze_objs->clean_up();
        maze_objs -= ({0});

        if(sizeof(maze_objs))
                return 1;
        else
        {
        */
                destruct(this_object());
                return 0;
//      }
}

void remove(string euid)
{
        string fname = base_name(this_object());
        object room;
        int x,y;

        if( handle_id )
                SCHEDULE_D->delete_event(handle_id);

        for( x=0;x<l;x++ )
                for( y=0;y<l;y++ )
                        if( objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))) )
                                destruct(room);
        if( room = find_object(sprintf("%s/entry",fname)) )
                destruct(room);
        if( room = find_object(sprintf("%s/exit",fname)) )
                destruct(room);
}

// ���ĳ���������Ƿ�����ҡ�
int is_player_in(object room)
{
        object *inv;
        inv = all_inventory(room);
        for (int i = 0;i < sizeof(inv) ; i++)
                if (userp(inv[i]))
                        return 1;
        return 0;
}

int have_player_in()
{
        string fname = base_name(this_object());
        object room;
        int x,y;
        for( x=0;x<l;x++ ) {
                for( y=0;y<l;y++ ) {
                        if(objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))))
                                if (is_player_in(room))
                                        return 1;
                }
        }

        if( objectp(room = find_object(sprintf("%s/entry",fname))) )
                if (is_player_in(room))
                        return 1;
        if( objectp(room = find_object(sprintf("%s/exit",fname))) )
                if ( is_player_in(room) )
                        return 1;

        return 0;
}

object *query_maze_players()
{
        string fname = base_name(this_object());
        object *inv, *ret;
        object room;
        int x,y;
        ret = ({});
        for( x=0;x<l;x++ ) {
                for( y=0;y<l;y++ ) {
                        if( objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))) ) {
                                        inv = all_inventory(room);
                                        for( int i=0;i<sizeof(inv);i++ )
                                                if( userp(inv[i]) )
                                                        ret += ({ inv[i] });
                        }
                }
        }

        if( objectp(room = find_object(sprintf("%s/entry",fname))) ) {
                inv = all_inventory(room);
                for( int i=0;i<sizeof(inv);i++ )
                        if( userp(inv[i]) )
                                ret += ({ inv[i] });
        }
        if( objectp(room = find_object(sprintf("%s/exit",fname))) ) {
                inv = all_inventory(room);
                for( int i=0;i<sizeof(inv);i++ )
                        if( userp(inv[i]) )
                                ret += ({ inv[i] });
        }

        return ret;
}

void refresh_maze()
{
        string fname = base_name(this_object());
        object room;
        int x,y;

        if (this_object()->have_player_in()) {
                SCHEDULE_D->set_event(10, 0, this_object(), "refresh_maze");
                return;
        }

        for( x=0;x<l;x++ )
                for( y=0;y<l;y++ )
                        if(objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))))
                                destruct(room);
        if( room = find_object(sprintf("%s/entry",fname)) )
                destruct(room);
        if( room = find_object(sprintf("%s/exit",fname)) )
                destruct(room);

        // �����Թ����ⷿ��
        special_rooms = copy(unique_rooms);

        return;
}

//      ��������Ҵ��Թ�����ߡ�
varargs int remove_all_players(object exile_room,string remove_msg)
{
        string fname = base_name(this_object());
        object room,*inv;
        int x,y,num;

        for( x=0;x<l;x++ ) {
                for( y=0;y<l;y++ ) {
                        if( objectp(room = find_object(sprintf("%s/%d/%d",fname,x,y))) ) {
                                if( remove_msg ) tell_room(room,remove_msg);
                                inv=all_inventory(room);
                                num=sizeof(inv);
                                while( num-- ) {
                                        if( !userp(inv[num]) ) continue;
                                        if( exile_room )
                                                inv[num]->move(exile_room);
                                        else
                                                inv[num]->move(VOID_OB);
                                }
                        }
                }
        }

        if( objectp(room = find_object(sprintf("%s/entry",fname))) ) {
                if( remove_msg ) tell_room(room,remove_msg);
                inv=all_inventory(room);
                num=sizeof(inv);
                while( num-- ) {
                        if( !userp(inv[num]) ) continue;
                        if( exile_room )
                                inv[num]->move(exile_room);
                        else
                                inv[num]->move(VOID_OB);
                }
        }

        if( objectp(room = find_object(sprintf("%s/exit",fname))) )     {
                if( remove_msg ) tell_room(room,remove_msg);
                inv=all_inventory(room);
                num=sizeof(inv);
                while( num-- ) {
                        if( !userp(inv[num]) ) continue;
                        if( exile_room )
                                inv[num]->move(exile_room);
                        else
                                inv[num]->move(VOID_OB);
                }
        }
}

void clear_maze_item(object user)
{
        object *inv, obj;
        inv = all_inventory(user);
        if( inv && sizeof(inv)>0 )
                foreach( obj in inv ) {
                        if( obj && obj->query("maze_item") )
                                destruct(obj);
                }
}

void set_display_coor(int flag)
{
        if( !intp(flag) ) flag = 0;
        display_coordinate = flag;
}

void set_display_map(int flag)
{
        if( intp(flag) && flag>=2 )
                map_status = MAP_DEEP;
        else if( intp(flag) && flag==1 )
                map_status = MAP_COMM;
        else
                map_status = MAP_NONE;
}

void set_maze_boss(object ob)
{
        if( objectp(ob) )
                maze_boss = ob;
}

void set_boss_weakly()
{
        int i, level;
        mapping skills;
        string *ks;
        if( !objectp(maze_boss) ) return;
        if( mapp(skills = maze_boss->query_skills()) ) {
                ks = keys(skills);
                for( i=0;i<sizeof(ks);i++ ) {
                        level = skills[ks[i]]+2;
                        maze_boss->set_skill(ks[i], level/2);
                }
        }
        return;
}

/**** ������Ԥ���Թ������Ľӿں��� ****/
// �Թ��ĵ��߳�
void set_maze_long(int mlong)
{
        if( !intp(mlong) )
                return;

        // ��СΪ 5����С��ûʲô���塣
        if( (mlong < 5) || mlong > MAX_LONG )
                return;

        l = mlong;
}

// �Թ���ʹ�õķ����ļ��� (****)
void set_valid_rooms(mixed room_files)
{
        if( stringp(room_files) ) {
                // �����Ƿ����
                if( file_size(sprintf("%s.c",room_files)) > 0 ) {
                        object ob = find_object(room_files);

                        if( !ob )
                                ob = load_object(room_files);
                        if( ob && ob->query("short") && ob->query("long") ) {
                                valid_rooms = ({ room_files });
                                switch_flag = 1;
                        }
                }
                return;
        } else if( arrayp(room_files) ) {
                foreach( string f in room_files ) {
                        object ob;

                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                        if( !ob = find_object(f) )
                                ob = load_object(f);
                        if( !ob || !ob->query("short") || !ob->query("long") )
                                return;
                }
                valid_rooms = room_files;
                switch_flag = 1;
                return;
        }

}

// �Թ��������̳е�����ĵ������ơ�
void set_inherit_room( mixed rooms )
{
        if( stringp(rooms) ) {
                // �˵����Ƿ����
                if( file_size(sprintf("%s.c",rooms)) > 0 )
                        inherit_rooms = ({ rooms });
                return;
        } else if( arrayp(rooms) ) {
                foreach( string f in rooms ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                inherit_rooms = rooms;
                return;
        }

        return;
}

// ��ڷ���(�����ڶ���)
void set_entry_dir(string dir)
{
        if( !stringp(dir) )
                return;

        // ��ڷ���ĺϷ��Լ��.
        if( member_array(dir,valid_dirs) == -1 )
                return;

        entry_dir = dir;
}

// �������������ӷ���
void set_link_entry_dir(string dir)
{
        if( !stringp(dir) || dir == "" )
                return;

        link_entry_dir = dir;
}

// �Թ�������������򵵰����ļ���
void set_link_entry_room(string lroom)
{
        if( !stringp(lroom) || lroom == "" )
                return;

        if( file_size(sprintf("%s.c",lroom)) <= 0 )
                return;

        link_entry_room = lroom;
}

// �Թ���ڷ�������꣬�����޷��ü򵥵ķ������Թ����갲����
// ����/�����ڣ������Ҫ�õ��Թ�������Ĺ�ϵ��
// ����������Ϊ�Թ��ǽ������������һ���֣����߳��Թ�����ʱ����Ծ������һ������
// ȱ���ǣ�һ�����Թ��������������ʵ�����ص��������Ҫ������Լ������ˣ�
// ����˵����Ҫ��100x100���Թ������� (1,1)�� (10,10)֮�䡣�������Լ���һ�°�
void set_link_entry_room_x(int x)
{
        if( !intp(x) ) link_entry_room_x=0;
        else    link_entry_room_x = x;
}
void set_link_entry_room_y(int y)
{

        if( !intp(y) ) link_entry_room_y=0;
        else    link_entry_room_y = y;
}
void set_link_entry_room_z(int z)
{
        if( !intp(z) ) link_entry_room_z=0;
        else    link_entry_room_z = z;
}

// ��������������ӷ���
void set_link_exit_dir(string dir)
{
        if( !stringp(dir) || dir == "" )
                return;

        link_exit_dir = dir;
}

// �Թ��������������򵵰����ļ���
void set_link_exit_room(string lroom)
{
        if( !stringp(lroom) || lroom == "" )
                return;

        if( file_size(sprintf("%s.c",lroom)) <= 0 )
                return;

        link_exit_room = lroom;
}

// �Թ���ڵĶ�����
void set_entry_short(string desc)
{
        if( !stringp(desc) || desc == "" )
                return;

        entry_short = desc;
}

// �Թ���ڵĳ�����
void set_entry_desc(string desc)
{
        if( !stringp(desc) || desc == "" )
                return;

        entry_desc = desc;
}

// �Թ����ڵĶ�����
void set_exit_short(string desc)
{
        if( !stringp(desc) || desc == "" )
                return;

        exit_short = desc;
}

// �Թ����ڵĳ�����
void set_exit_desc(string desc)
{
        if( !stringp(desc) || desc == "" )
                return;

        exit_desc = desc;
}

// �Թ�����Ķ�����
void set_maze_room_short(string desc)
{
        if( !stringp(desc) || desc == "" )
                return;

        maze_room_short = desc;
}

// �Թ����������������ж�������������ÿ����
// ���ʱ���������ѡ��һ����
void set_maze_room_desc(mixed desces)
{
        if( stringp(desces) ) {
                maze_room_desc = ({ desces });
                return;
        } else if(arrayp(desces)) {
                foreach( string desc in desces )
                        if( !stringp(desc) )
                                return;
                maze_room_desc = desces;
                return;
        }
}

// �Թ������Ƿ�Ϊ���ⷿ��
void set_outdoors(int outd)
{
        if( !intp(outd) )
                return;

        if( outd )
                is_outdoors = 1;
}

// �Թ��еĹ���
void set_maze_npcs(mixed npc)
{
        if( stringp(npc) ) {
                // �˵����Ƿ����
                if( file_size(sprintf("%s.c",npc)) > 0 )
                        maze_npcs = ({ npc });
                return;
        } else if( arrayp(npc) ) {
                foreach( string f in npc ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                maze_npcs = npc;
                return;
        } else if( mapp(npc) ) {
                mixed ns;

                ns = keys(npc);
                foreach( string f in ns ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                maze_npcs = npc;
                return;
        }
        return;
}

// �Թ���ڵĹ���
void set_entry_npcs(mixed npc)
{
        if( stringp(npc) ) {
                // �˵����Ƿ����
                if( file_size(sprintf("%s.c",npc)) > 0 )
                        entry_npcs = ({ npc });
                return;
        } else if( arrayp(npc) ) {
                foreach( string f in npc ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                entry_npcs = npc;
                return;
        } else if( mapp(npc) ) {
                mixed ks;

                ks = keys(npc);
                foreach( string f in ks ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                entry_npcs = npc;
                return;
        }
        return;
}

// �Թ����ڵĹ���
void set_exit_npcs(mixed npc)
{
        if( stringp(npc) ) {
                // �˵����Ƿ����
                if( file_size(sprintf("%s.c",npc)) > 0 )
                        exit_npcs = ({ npc });
                return;
        } else if( arrayp(npc) ) {
                foreach( string f in npc ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                exit_npcs = npc;
                return;
        } else if( mapp(npc) ) {
                mixed ks;

                ks = keys(npc);
                foreach( string f in ks ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                exit_npcs = npc;
                return;
        }
        return;
}

void set_unique_room(mixed room)
{
        if( stringp(room) ) {
                // �˵����Ƿ����
                if( file_size(sprintf("%s.c",room)) > 0 )
                        unique_rooms = ({ room });
        } else if( arrayp(room) ) {
                foreach( string f in room ) {
                        if( !stringp(f) || f == "" )
                                return;
                        if( file_size(sprintf("%s.c",f)) <= 0 )
                                return;
                }
                unique_rooms = room;
        }
        special_rooms = copy(unique_rooms);
        return;
}

void set_center_room(string room)
{
        if( !stringp(room) || room == "" )
                return;
        if( file_size(sprintf("%s.c",room)) > 0 )
                center_room = room;
        return;
}

// �Թ����������
void set_maze_boxs(int number)
{
        if( intp(number) && number>=1 )
                box_num = number;
}

// �Թ����������
void set_maze_traps(int number)
{
        if( intp(number) && number>=1 )
                trap_num = number;
}

// �Թ�ˢ��
void set_maze_refresh(int refresh)
{
        if( intp(refresh) && refresh>=1 )
                refresh_delay = refresh;
}

// �Թ���Ʒ���������
void set_maze_nodeath(int flag)
{
        if( intp(flag) && flag>=1 )
                is_nodeath = flag;
}

// �Թ��еĹ�����ֿ�����
void set_npcs_rate(int rate)
{
        if( !intp(rate) )
                return;

        random_rate = rate;
}

void set_lonely_create(int flag)
{
        if( intp(flag) && flag>=1 )
                lonely_create = flag;
}
/**** ������Ԥ���Թ������Ľӿں��� ****/

// �����Թ����䣬�� VIRTUAL_D ���á�
nomask object query_maze_room(string str)
{
        int idx,x,y,exits;
        int box_type,trap_type;
        object ob,obj;
        string f;
        int unique_flag;

        /*
        if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
                return 0;
        */

        if( !stringp(str) || str == "" )
                return 0;

        if( !maze_built ) // �Թ�δ����
                create_maze();
        if( !maze_built )
                return 0;

        if( !random_rate )
                random_rate = 50; // �����ڷ��� npc �Ŀ�����

        if( str == "entry" ) {     // �Թ���ڷ���
                f = inherit_rooms[random(sizeof(inherit_rooms))];
                //ob = new(f);
                ob = load_object(f);
                if( !ob )
                        return 0;
                ob->set("short",entry_short);
                ob->set("long",entry_desc);
                ob->set("maze", 1);
                ob->set("no_magic", 1);
                ob->set("virtual_room",1);
                if( is_outdoors )
                        ob->set("outdoors",1);
                if( is_nodeath )
                        ob->set("no_death",1);
                if( link_entry_room ) ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
                ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y));
                ob->set("coor/x",link_entry_room_x);
                ob->set("coor/y",link_entry_room_y);
                ob->set("coor/z",link_entry_room_z);
                ob->set("mazeobj", base_name(this_object()));
                ob->set("maze/x", enter->x);
                ob->set("maze/y", enter->y);
                if( arrayp(entry_npcs) && sizeof(entry_npcs) ) {
                        ob->set("objects",([
                                entry_npcs[random(sizeof(entry_npcs))] : 1,
                        ]));
                        ob->setup();
                } else if( mapp(entry_npcs) && sizeof(entry_npcs) ) {
                        ob->set("objects", entry_npcs);
                        ob->setup();
                }

                return ob;
        }

        if( str == "exit" ) {      // �Թ����ڷ���
                f = inherit_rooms[random(sizeof(inherit_rooms))];
                //ob = new(f);
                ob = load_object(f);
                if( !ob )
                        return 0;

                ob->set("short",exit_short);
                ob->set("long",exit_desc);
                ob->set("maze", 1);
                ob->set("no_magic", 1);
                ob->set("virtual_room",1);
                if( is_outdoors )
                        ob->set("outdoors",1);
                if( is_nodeath )
                        ob->set("no_death",1);
                if( link_exit_room ) ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
                ob->set(sprintf("exits/%s",entry_dir),mroom_fname(leave->x,leave->y));
                ob->set("mazeobj", base_name(this_object()));
                ob->set("maze/x", leave->x);
                ob->set("maze/y", leave->y);
                if( arrayp(exit_npcs) && sizeof(exit_npcs) ) {
                        ob->set("objects",([
                                exit_npcs[random(sizeof(exit_npcs))] : 1,
                        ]));
                        ob->setup();
                } else if( mapp(exit_npcs) && sizeof(exit_npcs) ) {
                        ob->set("objects", exit_npcs);
                        ob->setup();
                }

                return ob;
        }

        idx = member_array('/', str);
        if( idx == -1 )
                return 0;

        if( !sscanf(str[0..idx-1],"%d",x) )
                return 0;
        if( !sscanf(str[idx+1..],"%d",y) )
                return 0;

        if( !exits = all[x][y] )
                return 0;

        // ����unique rooms4�����䣬������λ��
        unique_flag = 0;
        if( exits&SPECIAL && sizeof(special_rooms) > 0 ) {
                unique_flag = 1;
                f = special_rooms[random(sizeof(special_rooms))];
                special_rooms -= ({ f });
        } else if( exits&CENTER ) {
                unique_flag = 1;
                f = center_room;
        } else if( exits&TRAP ) {
                f = TRAP_ROOM;
        } else {
                // ��ͬ�Ĵ�������
                if( switch_flag )
                        f = valid_rooms[random(sizeof(valid_rooms))];
                else
                        f = inherit_rooms[random(sizeof(inherit_rooms))];
        }

        //ob = new(f);
        ob = load_object(f);
        if( !ob )
                return 0;

        if( !switch_flag && !unique_flag ) {
                ob->set("short",maze_room_short);
                ob->set("long",maze_room_desc[random(sizeof(maze_room_desc))]);
                ob->set("maze", 1);
                ob->set("no_magic", 1);
                ob->set("virtual_room",1);
                if( is_outdoors )
                        ob->set("outdoors",1);
                if( is_nodeath )
                        ob->set("no_death",1);
        }

        if( exits&TRAP ) {
                trap_type = random(100);
                if( trap_type > 97 )
                        ob->set("maze/trap", LOSTMAP);    // �ٷ�֮һʮ
                else if( trap_type < 20 )
                        ob->set("maze/trap", TRIP);       // �ٷ�֮��ʮ
                else if( trap_type < 40 )
                        ob->set("maze/trap", CHANGEMAP);  // �ٷ�֮��ʮ
                else if (trap_type < 70)
                        ob->set("maze/trap", WOUND);      // �ٷ�֮��ʮ
                else
                        ob->set("maze/trap", BUSY);
        }

        // �������������Թ���С�����巿������
        ob->set("coor/x",x*10-l+link_entry_room_x);
        ob->set("coor/y",y*10-to_int(l/2)+link_entry_room_y);
        ob->set("coor/z",link_entry_room_z);
        ob->set("mazeobj", base_name(this_object()));
        ob->set("maze/x", x);
        ob->set("maze/y", y);

        if( exits&W )
                ob->set("exits/west",mroom_fname(x-1,y));
        else
                ob->set("exits/west",mroom_fname(x,y));
        if( exits&E )
                ob->set("exits/east",mroom_fname(x+1,y));
        else
                ob->set("exits/east",mroom_fname(x,y));
        if( exits&N )
                ob->set("exits/north",mroom_fname(x,y+1));
        else
                ob->set("exits/north",mroom_fname(x,y));
        if( exits&S )
                ob->set("exits/south",mroom_fname(x,y-1));
        else
                ob->set("exits/south",mroom_fname(x,y));

        if( (x == enter->x) && (y == enter->y) )
                ob->set(sprintf("exits/%s",entry_dir),
                        sprintf("%s/entry",base_name(this_object())));
        if( (x == leave->x) && (y == leave->y) )
                ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
                        sprintf("%s/exit",base_name(this_object())));

        if( !switch_flag && !unique_flag ) {
                if( mapp(maze_npcs) && sizeof(maze_npcs) && (random(100) <= random_rate) ) {
                        ob->set("objects", maze_npcs);
                        ob->setup();
                } else if( arrayp(maze_npcs) && sizeof(maze_npcs) && (random(100) <= random_rate) ) {
                        ob->set("objects",([
                                maze_npcs[random(sizeof(maze_npcs))] : 1,
                        ]));
                        ob->setup();
                }
        }

        if( exits&MAP ) {
                obj = new(BOX_OB);
                obj->set("maze/box", SPECIAL_MAP);
                obj->move(ob);
        } else if( exits&BOX ) {
                obj = new(BOX_OB);
                box_type = random(100);
                if( box_type > 97 )
                        obj->set("maze/box", SPECIAL_DAN);     //�ٷ�֮��
                else if( box_type > 94 )
                        obj->set("maze/box", JINKUAI);         //�ٷ�֮��
                else if( box_type < 15 )
                        obj->set("maze/box", GOLD);            //�ٷ�֮ʮ��
                else if( box_type < 65 )
                        obj->set("maze/box", OBJ);             //�ٷ�֮��ʮ
                else if( box_type < 85 )
                        obj->set("maze/box", SPECIAL_OBJ);     //�ٷ�֮��ʮ
                else {
                        if( objectp(maze_boss) )
                                obj->set("maze/box", NPC_SKILL);
                        else
                                obj->set("maze/box", SPECIAL_OBJ); //�ٷ�֮ʮ
                }

                obj->move(ob);
        }

        return ob;
}

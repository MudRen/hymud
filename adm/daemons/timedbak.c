// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>
#include <command.h>

inherit F_DBASE;

#define MIN             0
#define HOUR            1
#define WDAY            2
#define MDAY            3
#define MON             4
#define YEAR            5

#define DATA_PATH       "/data/timed.o"
#define MAZE_DOOR1      "/clone/misc/maze_door1"

#define VRM00      "vrm00"
#define VRM01      "vrm01"
#define VRM02      "vrm02"
#define VRM03      "vrm03"
#define VRM04      "vrm04"
#define VRM05      "vrm05"
#define VRM06      "vrm06"
#define VRM07      "vrm07"
#define VRM08      "vrm08"
#define VRM09      "vrm09"
#define VRM10      "vrm10"
#define VRM11      "vrm11"

int gametime;
static int realtime;
static int tick;
static mapping event = allocate_mapping(0);
static int *real_time = allocate(6);
static int *game_time = allocate(6);

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ";

if (str=="binghuodao")  

	output="����";

if (str=="city")  

	output="����";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="������";

if (str=="city4" || str=="changan")   

	output="������";

if (str=="dali")  

	output="����";

if (str=="emei")  

	output="��üɽ";

if (str=="foshan")  

	output="��ɽ";

if (str=="gaibang")  

	output="ؤ��";

if (str=="gaochang")  

	output="�߲��Թ�";

if (str=="guanwai")  

	output="����";

if (str=="guiyun")  

	output="����ׯ";

if (str=="gumu")  

	output="��Ĺ��";

if (str=="hangzhou")  

	output="����";

if (str=="heimuya")  

	output="��ľ��";

if (str=="hengshan")  

	output="��ɽ";

if (str=="henshan")  

	output="��ɽ";

if (str=="huanghe")  

	output="�ƺӾ���";

if (str=="huashan")  

	output="��ɽ";

if (str=="jinshe")  

	output="����ɽ��";

if (str=="lingjiu")  

	output="���չ�";

if (str=="lingzhou")  

	output="����";

if (str=="meizhuang")  

	output="÷ׯ";

if (str=="mingjiao")  

	output="����";

if (str=="qingcheng")  

	output="���ɽ";

if (str=="quanzhen")  

	output="ȫ����";

if (str=="quanzhou")  

	output="Ȫ��";

if (str=="shaolin")  

	output="������";

if (str=="shenlong")  

	output="������";

if (str=="songshan")  

	output="��ɽ";

if (str=="suzhou")  

	output="����";

if (str=="taishan")  

	output="̩ɽ";

if (str=="taohua")  

	output="�һ���";

if (str=="tianlongsi")  

	output="������";

if (str=="wanjiegu")  

	output="��ٹ�";

if (str=="wudang")  

	output="�䵱ɽ";

if (str=="xiakedao")  

	output="���͵�";

if (str=="xiangyang")  

	output="������";

if (str=="xiaoyao")  

	output="��ң��";

if (str=="xingxiu")  

	output="���޺�";

if (str=="xueshan")  

	output="ѩɽ��";

if (str=="xuedao")  

	output="��ѩɽ";

if (str=="mr")  

	output="Ľ������";

if (str=="kunlun")  

	output="����ɽ";

if (str=="tiezhang")  

	output="������";

if (str=="huizhu")  

	output="���岿��";

if (str=="yinju")  

	output="һ�ƴ�ʦ��";

if (str=="menggu")  

	output="�ɹŲ�ԭ";

if (str=="qianjin")  

	output="����ǧ��¥";

if (str=="lingshedao")  

	output="���ߵ�";

if (str=="ruzhou")  

	output="���ݳ�";

if (str=="kunming")  

	output="����";

if (str=="jingzhou")  

	output="����";

if (str=="yanjing")  

	output="�ྩ";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="����";

if (str=="jyguan")  

	output="�����Ա�������";

if (str=="changcheng")  

	output="�����Ա�����";

if (str=="fairyland")  

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ�";

if (str=="feihu")  

	output="��������";

if (str=="wuguan")  

	output="�������";

if (str=="village")  

	output="��ɽ��";

if (str=="taohuacun")  

	output="�һ���";

if (str=="pingan")  

	output="ƽ����";

if (str=="lingxiao")  

	output="������";

if (str=="wudujiao")  

	output="�嶾��";

if (str=="hj")  

	output="��ɽ����ԭ";
if (str=="dali/yuxu")  

	output="���������";
if (str=="dali/wuliang")  

	output="��������ɽ";
if (str=="huanghe/yyd")  

	output="�ƺ�����";
if (str=="kaifeng")  

	output="�����";
if (str=="feitian")  

	output="����������";
if (str=="japan")  

	output="�ձ���";
if (str=="tangmen")  

	output="����";
if (str=="luoyang")  

	output="������";

if (str=="chengdu" || str=="city3")  

	output="�ɶ�";

if (str=="baihuagu")  

	output="�ٻ���";

if (str=="heizhao")  

	output="�ٻ��ȡ�����";

if (str=="jiaxing")  

	output="����";

if (str=="shiliang")  

	output="�¼�ׯ";

if (str=="wuyi")  

	output="����ɽ��";

if (str=="yanping")  

	output="��ƽ��";
	

if (str=="jiangling")  
{
	output="�����";
}

if (str=="yueyang")  
{
	output="������";	
}

if (str=="qilian")  
{
	output="����ɽ";	
}

if (str=="shouxihu")  
{
	output="������";	
}

if (str=="wuxi")  
{
	output="������";	
}

if (str=="yixing")  
{
	output="���˳�";	
}
if (str=="taiwan")  
{
	output="̨�����";	
}
if (str=="nanyang")  
{
	output="��������";	
}
if (str=="nanshaolin")  
{
	output="�����ֵ���";	
}

if (str=="cangzhou")  
{
	output="���ݵ���";	
}

if (str=="tanggu")  
{
	output="�����ǵ���";	
}

if (str=="yunhe")  
{
	output="�������˺�";	
}

if (str=="hainan")  
{
	output="���ϵ�";	
}

if (str=="jindezheng")  
{
	output="������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ";	
}

if (str=="jinling")  
{
	output="�����";	
}

if (str=="sandboy")  
{
	output="����ũ��";	
}

if (str=="huangshan")  
{
	output="��ɽ";	
}

if (str=="yubifeng")  
{
	output="��ʷ�";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="���� ����ɽ";	
}

if (str=="annan")  
{
	output="���ϸ���";	
}

if (str=="taiyuan")  
{
	output="̫ԭ����";	
}

if (str=="hefei")  
{
	output="�Ϸʸ���";	
}

if (str=="jiujiang")  
{
	output="�Ž�����";	
}

if (str=="baling")  
{
	output="���긽��";	
}

if (str=="xinjiang")  
{
	output="�½�����";	
}
if (str=="dingxiang")  
{
	output="���帽��";	
}
if (str=="suiye")  
{
	output="��Ҷ����";	
}


if (str=="mayi")  
{
	output="���ر߽�����";	
}
if (str=="xuzhou")  
{
	output="���ݳǸ���";	
}
if (str=="jinan")  
{
	output="���ϳǸ���";	
}
if (str=="guizhou")  
{
	output="�����Ǹ���";	
}

if (str=="nanchang")  
{
	output="�ϲ��Ǹ���";	
}


if (str=="changsha")  
{
	output="��ɳ�Ǹ���";	
}


if (str=="zhongzhou")  
{
	output="���ݳǸ���";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�����";	
}

return output;
}

    object get_object(string name) 
    { 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 

static mapping vrm_name_list = ([
        "vrm00"  : "ԭʼɭ��",
        "vrm01"  : "�����Թ�",
        "vrm02"  : "��֮��ͷ",
        "vrm03"  : "��֮����",
        "vrm04"  : "����֮԰",
        "vrm05"  : "����֮��",
        "vrm06"  : "����ɭ��",
        "vrm07"  : "�ٻ�֮��",
        "vrm08"  : "����ɽ��",
        "vrm09"  : "��������",
        "vrm10"  : "�޵��ܶ�",        	        	        	        	        	        	        	
        "vrm11"  : "����ħ��",        	        	        	        	        	        	        	        	
]);

void auto_relaim()
{
        int i;
        if (i = reclaim_objects())
                CHANNEL_D->do_channel( this_object(), "sys",
                        sprintf("ϵͳ�Զ���� %d ��������", i));
}

void game_new_year()
{
        shout( WHT "\n" + CHINESE_MUD_NAME + CHINESE_D->chinese_number(game_time[YEAR]) + "�������������������ڣ�����\n" NOR);
}

void real_new_year()
{
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
        shout( WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
}

void broadcast_message()
{
        shout(HIW "��ϵͳ��ʾ�������Ա���ܸ���Ļ�Ա����(help member)��������鿴�����ļ�������\n" NOR);
        shout(HIW "��ϵͳ��ʾ��Ŀǰ��Ϸ��ɾ���ڲ⣬�������̳����������ע����ϷID��\n"
              HIW "            �����������Ͽɿɻ�÷��Ʊ� http://www.nbyingqi.com.cn\n" NOR);
}

void double_reward_start()
{
        //shout(BEEP BLINK HIR"����Աͨ�桿���ڵ�ʱ��Ϊ 20 �㣬ϵͳ���Ż�Ա˫������ʱ�俪ʼ������\n"NOR);
}

void double_reward_end()
{
        //shout(BEEP BLINK HIR"����Աͨ�桿���ڵ�ʱ��Ϊ 24 �㣬ϵͳ���Ż�Ա˫������ʱ�����������\n"NOR);
}





void create_vrm_entry(string arg)
{
        object room, maze_door;
        string filename;
        string rooms;
string *dir2;        
        switch( arg )
        {
        case VRM00 :    
                filename = "/d/kunming/nanmen";  
                room = get_object(filename);          
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0000/entry");
                maze_door->move(room);
                break;

        case VRM01 :    
                filename = "/d/xiakedao/wangyun";  
                room = get_object(filename);          
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0001/entry");
                maze_door->move(room);
                break;
        case VRM02 :
                filename = "/d/guanwai/tianchi1";  
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0002/entry");
                maze_door->move(room);
                break;
        case VRM03 :
                filename = "/d/xueshan/hubian3";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0003/entry");
                maze_door->move(room);
                break;
        case VRM04 :
                filename = "/d/taiwan/riyuetan";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0004/entry");
                maze_door->move(room);
                break;
        case VRM05 :
                filename = "/d/qingcheng/path1";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0005/entry");
                maze_door->move(room);
                break;
        case VRM06 :
                filename = "/d/hengshan/daziling";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0006/entry");
                maze_door->move(room);
                break;
        case VRM07 :
                filename = "/d/xiangyang/caodi5";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0007/entry");
                maze_door->move(room);
                break;
        case VRM08 :
                filename = "/d/emei/yunufeng";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0008/entry");
                maze_door->move(room);
                break;
        case VRM09 :
                filename = "/d/songshan/fengchantai";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0009/entry");
                maze_door->move(room);
                break;
        case VRM10 :
                filename = "/d/dali/yuxiashan";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0010/entry");
                maze_door->move(room);
                break;
        case VRM11 :
                filename = "/d/xizang/timetree";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0011/entry");
                maze_door->move(room);
                break;
                                                                                                                                               
        default:
                return;
        }


dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
log_file("log", ctime(time())+" �����Թ���" + arg +"\n", 1);        


        
        message("vision", HIG "��" HIR "��������" HIG "��" HIW +
                room->query("short") + HIW "(" + rooms + 
                ")һ��������" + vrm_name_list[arg] + HIW "��\n" NOR, users());
        
        SCHEDULE_D->set_event(3600, 0, this_object(), "close_vrm_entry", arg, room, maze_door);
}

void close_vrm_entry(string arg, object room, object maze_door)
{
        string rooms;
string *dir2; 
        if ( !room || !maze_door ) return;
        
        destruct(maze_door);
    dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
        message("vision", HIG"��" HIR"��������" HIG"��" HIW +
                room->query("short") + HIW "(" + rooms+ ")һ�����ֵ�" + 
                vrm_name_list[arg] + HIW "��ʧ�ˡ�\n" NOR, users());
}

// ��Ϸʱ��Ĺ����ų�
static mixed  game_crontab = ({
//"min hour wday mday mon year" : ({ function })
"0 0 * 0 0 *"           , (: game_new_year :),                  "ÿ�귢һ�κ��",
});

// ��ʵʱ��Ĺ����ų�
static mixed  real_crontab = ({
"0 0 * 0 0 *"           , (: real_new_year :),                  "��ʵʱ�����",
"* * * * * *"           , (: SCHEDULE_D->start_events() :),     "ÿ���Ӽ���ų��������",
"1 */2 * * * *"         , (: create_vrm_entry(VRM00) :),  "ÿ 2 ��Сʱˢ��һ��",
"5 */2 * * * *"         , (: create_vrm_entry(VRM01) :),   "ÿ 2 ��Сʱˢ��һ��",
"9 */3 * * * *"         , (: create_vrm_entry(VRM02) :),   "ÿ 3 ��Сʱˢ��һ��",
"15 */3 * * * *"         , (: create_vrm_entry(VRM03) :),   "ÿ 3 ��Сʱˢ��һ��",
"20 */4 * * * *"         , (: create_vrm_entry(VRM04) :),   "ÿ 4 ��Сʱˢ��һ��",
"25 */4 * * * *"         , (: create_vrm_entry(VRM05) :),   "ÿ 4 ��Сʱˢ��һ��",
"30 */5 * * * *"         , (: create_vrm_entry(VRM06) :),   "ÿ 5 ��Сʱˢ��һ��",
"35 */5 * * * *"         , (: create_vrm_entry(VRM07) :),   "ÿ 5 ��Сʱˢ��һ��",
"35 */6 * * * *"         , (: create_vrm_entry(VRM08) :),   "ÿ 6 ��Сʱˢ��һ��",
"45 */6 * * * *"         , (: create_vrm_entry(VRM09) :),   "ÿ 6 ��Сʱˢ��һ��",						
"50 */7 * * * *"         , (: create_vrm_entry(VRM10) :),   "ÿ 7 ��Сʱˢ��һ��",						
"55 */7 * * * *"         , (: create_vrm_entry(VRM11) :),   "ÿ 7 ��Сʱˢ��һ��",						
			
});

// ��ȡ�� call_out ֮����
void add_event(function fevent, int delay_time)
{
        if( !sizeof(event) || !event[fevent] )
                event = ([ fevent : delay_time ]);
        else
                event[fevent] = delay_time;
}

// ִ���¼�
void exec_event(function fevent)
{
        if( objectp(function_owner(fevent)) )
                evaluate(fevent);

        map_delete(event, fevent);
}

string replace_ctime(int t)
{
        string month, ctime = ctime(t);

        switch(ctime[4..6])
        {
                case "Jan"      :       month = "01";break;
                case "Feb"      :       month = "02";break;
                case "Mar"      :       month = "03";break;
                case "Apr"      :       month = "04";break;
                case "May"      :       month = "05";break;
                case "Jun"      :       month = "06";break;
                case "Jul"      :       month = "07";break;
                case "Aug"      :       month = "08";break;
                case "Sep"      :       month = "09";break;
                case "Oct"      :       month = "10";break;
                case "Nov"      :       month = "11";break;
                case "Dec"      :       month = "12";break;
        }

        return sprintf("%s/%s/%s %s", month, (ctime[8]==' '?"0"+ctime[9..9]:ctime[8..9]), ctime[<4..<1], ctime[11..15]);
}

string season_period(int m)
{
        switch(m)
        {
                case 2..4:      return "��";
                case 5..7:      return "��";
                case 8..10:     return "��";
                case 11:        return "��";
                case 0..1:      return "��";
                default:        return 0;
        }
}

string week_period(int w)
{
        switch(w)
        {
                case 0:         return "��";
                case 1:         return "һ";
                case 2:         return "��";
                case 3:         return "��";
                case 4:         return "��";
                case 5:         return "��";
                case 6:         return "��";
                default:        return 0;
        }
}

string hour_period(int h)
{
        switch(h)
        {
                case 0..5:      return "�賿";
                case 6..11:     return "����";
                case 12:        return "����";
                case 13..18:    return "����";
                case 19..23:    return "����";
                default:        return 0;
        }
}

/* �ش�ʱ������ ({ �� ʱ �� �� �� �� }) */
int *query_gametime_array()
{
        return game_time;
}

int *query_realtime_array()
{
        return real_time;
}

/* �ش���λʱ���ʾ ���� 3:39 */
string gametime_digital_clock()
{
        int h = game_time[HOUR];
        int m = game_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}
string realtime_digital_clock()
{
        int h = real_time[HOUR];
        int m = real_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}

string time_description(string title, int *t)
{
        return sprintf( NOR WHT+title+NOR"%s�꣬%s��%s��%s������%s��%s%s��%s��"NOR
            ,t[YEAR]==1?"Ԫ":CHINESE_D->chinese_number(t[YEAR])
            ,season_period(t[MON])
            ,!t[MON]?"Ԫ":CHINESE_D->chinese_number(t[MON]+1)
            ,CHINESE_D->chinese_number(t[MDAY]+1)
            ,week_period(t[WDAY])
            ,hour_period(t[HOUR])
            ,CHINESE_D->chinese_number(t[HOUR] > 12 ? t[HOUR]%12 : t[HOUR])
            ,CHINESE_D->chinese_number(t[MIN])
        );
}

string game_time_description()
{
        return time_description(CHINESE_MUD_NAME, game_time);
}

string real_time_description()
{
        return time_description("��Ԫ", real_time);
}

int query_game_time()
{
        return gametime*60;
}

int query_real_time()
{
        return realtime;
}

int *analyse_time(int t)
{
        int *ret = allocate(6);
        string ctime;

        ctime = ctime(t);

        sscanf(ctime,"%*s %*s %d %d:%d:%*d %d",ret[MDAY], ret[HOUR], ret[MIN], ret[YEAR]);

        switch(ctime[0..2])
        {
                case "Sun": ret[WDAY] = 0; break;
                case "Mon": ret[WDAY] = 1; break;
                case "Tue": ret[WDAY] = 2; break;
                case "Wed": ret[WDAY] = 3; break;
                case "Thu": ret[WDAY] = 4; break;
                case "Fri": ret[WDAY] = 5; break;
                case "Sat": ret[WDAY] = 6; break;
                default   : return 0;
        }

        switch(ctime[4..6])
        {
                case "Jan": ret[MON] = 0; break;
                case "Feb": ret[MON] = 1; break;
                case "Mar": ret[MON] = 2; break;
                case "Apr": ret[MON] = 3; break;
                case "May": ret[MON] = 4; break;
                case "Jun": ret[MON] = 5; break;
                case "Jul": ret[MON] = 6; break;
                case "Aug": ret[MON] = 7; break;
                case "Sep": ret[MON] = 8; break;
                case "Oct": ret[MON] = 9; break;
                case "Nov": ret[MON] = 10; break;
                case "Dec": ret[MON] = 11; break;
                default   : return 0;
        }
        ret[MDAY] -= 1;
        return ret;
}

void process_crontab(mixed * crontab, int *timearray)
{
        int i, j, row, divider, fit, timecost, crontabsize;
        string s, script, note, *timescript;
        function fp;

        crontabsize = sizeof(crontab);

        for(row=0;row<crontabsize;row+=3)
        {
                reset_eval_cost();
                script = crontab[row];
                fp = crontab[row+1];
                note = crontab[row+2];

                timescript = allocate(6);

                // %s%*(( |\t)+) ����˼�� %s(�ո� or \t ����)���� + ��������һ��һ�����Ϸ��ϵĵ�Ԫ
                if( sscanf(script, "%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s",
                        timescript[0],
                        timescript[1],
                        timescript[2],
                        timescript[3],
                        timescript[4],
                        timescript[5]) != 11 ) continue;

                for( i=0;i<6;i++ )
                {
                        fit = 0;

                        foreach(s in explode(timescript[i], ","))
                        {
                                j = to_int(s);

                                // ��ͬ��mudos��undefinedp�������ص�ֵ������
                                if( s == "*" || (sscanf(s, "*/%d", divider) && !(timearray[i]%divider)) )
                                {
                                        fit = 1;
                                        break;
                                }
                                else if( !undefinedp(j) )
                                {
                                        if( j == timearray[i] )
                                        {
                                                fit = 1;
                                                break;
                                        }
                                }
                        }

                        if( !fit ) break;
                }

                if( !fit )
                        continue;

                timecost = time_expression {
                        catch(evaluate(fp));
                };

                if( timecost > 1000000 )
                        CHANNEL_D->do_channel(this_object(), "sys",
                                sprintf("TIME_D: crontab '%s'(%.6f sec) %s", script, timecost/1000000., note));

        }
}

// ��������ÿ��ִ�к�ʽ
void process_per_second()
{

}

void reset_gametime()
{
        gametime = -20000000;
}

/* ��Ϸʱ��ÿһ����(��ʵ��ʱ��ÿ2.5��)ִ��һ�� process_gametime */
void process_gametime()
{
        game_time = analyse_time(++gametime * 60);
        game_time[YEAR] -= 1970;

        process_crontab(game_crontab, game_time);
}

/* ��ʵʱ��ÿһ����ִ��һ�� process_realtime */
void process_realtime()
{
        mixed * localtime = localtime(realtime);

        real_time = ({
                localtime[LT_MIN],
                localtime[LT_HOUR],
                localtime[LT_WDAY],
                localtime[LT_MDAY]-1,
                localtime[LT_MON],
                localtime[LT_YEAR] });
        
        // ÿ��ִ�к�ʽ
        process_per_second();

        //if( !localtime[LT_SEC] )
        //        process_crontab(real_crontab, real_time);
}

// ÿ 1 ������һ��
// ʵ��һ�������Ϸһ��

void heart_beat()
{
        realtime = time();

        // ִ�� event ����
        if( sizeof(event) )
        foreach( function fevent, int delay_time in event )
                if( !--event[fevent] )
                        exec_event(fevent);

        // ÿ 2 ���൱����Ϸһ����, time ÿ���� 1 ������Ϸһ����
        if( !(++tick % 2) )
                process_gametime();

        process_realtime();
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "ʱ�侫��");
        write("ʱ�侫���Ѿ�������\n");
        if( !restore_object(DATA_PATH) )
                save_object(DATA_PATH);

        game_time = allocate(6);
        real_time = allocate(6);
        event = allocate_mapping(0);

        process_gametime();
/*
create_vrm_entry(VRM00);
create_vrm_entry(VRM01);
create_vrm_entry(VRM02);
create_vrm_entry(VRM03);
create_vrm_entry(VRM04);
create_vrm_entry(VRM05);
create_vrm_entry(VRM06);
create_vrm_entry(VRM07);
create_vrm_entry(VRM08);
create_vrm_entry(VRM09);
create_vrm_entry(VRM10);
create_vrm_entry(VRM11);
*/


        set_heart_beat(1);
}

int remove()
{
        return save_object(DATA_PATH);
}

string query_name()
{
        return "ʱ��ϵͳ(TIME_D)";
}





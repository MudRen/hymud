#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;36m����֮����[2;37;0m", ({ "kunlun hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;36m	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ� 
	����ʫ���ζϣ��Ϲ����� 
	�ѽ���Ȼ�����޴��й��ۡ� 
 
	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� 
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ�����������Ǯ��[1;36m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[35m��׼[2;37;0m [31m��[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ����:[1;36m����[2;37;0m 
����:[31m����[2;37;0m ����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�Ʊ�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "�Ʊ�");
		set("value", 25000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 33);
    set("armor_prop/parry", 24);
    set("armor_prop/attack", 74);


    set("armor_prop/armor", 251);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 66);
    set("armor_prop/qi", 65);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 892);

    set("wtypeA",8);
    set("wtypeB",3);
    set("wtypeC",5);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",3);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";
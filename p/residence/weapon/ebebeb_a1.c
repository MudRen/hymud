#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;37m��Ӱ��[2;37;0m", ({ "good cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
����֮��װ[2;37;0m����һ�����ޱȼ�Ӳ��[1;37m����[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ��ذ˽�������Ǯ��[1;37m����֮��װ[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m��ʥ[2;37;0m ��Դ:[33mһ��[2;37;0m 
����:[36m����[2;37;0m ����:[36m����[2;37;0m 
��ʯ:[36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ľ����");
		set("value", 9000);
		set("armor_prop/intelligence",8);
		set("armor_prop/strength",24);
		set("armor_prop/karey",9);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",8);
		set("armor_prop/constitution",17);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 17);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 626);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 16);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 32);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 104);

    set("wtypeA",1);
    set("wtypeB",2);
    set("wtypeC",2);
    set("wtypeD",1);
    set("wtypeE",1);
    set("wtypeF",2);
    set("wtypeG",3);
    set("wtypeH",5);
    set("wtypeI",3);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";
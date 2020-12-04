#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;37m°ËØÔÖ®Åû·ç[2;37;0m", ({ "bagua armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;37m°ËØÔÓĞ¡°Ğİ¡±¡°Éú¡±¡°ÉË¡±¡°¶Å¡±¡°ËÀ¡±¡°¾°¡±¡°¾ª¡±¡°¿ª¡±Ö®±ğ£¬´´×ÔÖî¸ğÎäºò£¬¼¯ÌìÏÂÍò±äÓÚÒ»Éí£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÁãÁ½ÁãÇ®µÄ[1;37m°ËØÔÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31mÎŞË«[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31m¿ªÔª[2;37;0m [1;34mµç[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[32m´Ö²Ú[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ²»ÀÏ:[34mÏ¸Ëé[2;37;0m ÍşÁ¦:[31m¾«ÖÂ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ·µÙ·ÒÖÜ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m±Ş·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "Ê·µÙ·ÒÖÜ");
		set("value", 25000);
		set("armor_prop/intelligence",16);
		set("armor_prop/strength",16);
		set("armor_prop/karey",24);
		set("armor_prop/percao",16);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 16);


    set("armor_prop/armor", 204);
    set("armor_prop/defense", 8);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 61);
    set("armor_prop/jing", 28);
    set("armor_prop/jingli", 28);
    set("armor_prop/damage", 112);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",4);
    set("wtypeE",14);
    set("wtypeF",12);
    set("wtypeG",13);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
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
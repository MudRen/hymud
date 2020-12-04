#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;33mĞùÔ¯[2;37;0m", ({ "qingyu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[37mÇàÓñÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÈı½ïÁùÁ½ÁãÇ®µÄ[37mÇàÓñÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[33mºÜ¸ß[2;37;0m [31m»ğ[2;37;0m:[35m±ê×¼[2;37;0m [1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;34mµç[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[34mÏ¸Ëé[2;37;0m ×ÏÊ¯:[36m²»´í[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 
ÖÜÌì:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÔÙĞøÇ°Ôµ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÍÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yunlongzi");
		set("ownername", "ÔÙĞøÇ°Ôµ");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 27);
    set("armor_prop/parry", 19);
    set("armor_prop/attack", 29);


    set("armor_prop/armor", 181);
    set("armor_prop/defense", 39);
    
    set("armor_prop/neili", 35);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",11);
    set("wtypeB",9);
    set("wtypeC",4);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",9);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";
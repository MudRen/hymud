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
	      set_name("[1;34mÇÇÒÀÎÚË¹Ö®¶Ü[2;37;0m", ({ "joeywus shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[1;34mÔÚÎ÷·½²éÀíÂüÍ³ÖÎµÄÊ±´ú£¬×î¼òÆÓµÄ½£Ò²ÄÜÖµÈıÍ·Ä¸Å£µÄ¼ÛÇ®¡£¶ø²éÀí´óµÛ×Ô¼ºµÄÄÇ°Ñ´«ÆæÊ½
µÄÉñ±ø¡°ÇÇÒÀÎÚË¹¡±¾İËµÊÇ°ëÈË°ëÉñµÄ¡°Î¤À¼Ìú½³¡±ËùÔì£¬ÄËµ±ÊÀ½çÉñ±ø£¡
[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÆßÁ½ÁãÇ®µÄ[1;34mÇÇÒÀÎÚË¹Ö®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[35m±ê×¼[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿Æ±È[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "¿Æ±È");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",0);
		set("armor_prop/karey",48);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 54);
    set("armor_prop/parry", 46);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 467);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 59);
    set("armor_prop/qi", 29);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 200);

    set("wtypeA",11);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",4);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",5);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "hammer",
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